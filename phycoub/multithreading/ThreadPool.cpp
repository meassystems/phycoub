#include "ThreadPool.h"

#include <thread>
#include <exception>

namespace phycoub
{

ThreadPool::ThreadPool()
{
    unsigned availableThreadCount = std::thread::hardware_concurrency();
    for ( uint32_t i = 0; i < availableThreadCount; ++i )
    {
        threads.emplace_back( std::thread( &ThreadPool::runTask, this ) );
    }
}

ThreadPool::~ThreadPool()
{
    try
    {
        waitAllTaskCompleted();
    }
    catch ( ... )
    {
    }

    {

        std::lock_guard< BlockType > lock( _taskQueueMutex );
        threadsStopFlag = true;
        // Необходимо делать под защитой очереди, чтобы не попасть в промежуток между
        // началом цикла и ожиданием уведомлений в исполнящих потоках
        _notifyThreadsContinueCv.notify_all();
    }

    for ( auto& thread : threads )
    {
        thread.join();
    }
}

void ThreadPool::pushTask( std::function< void() > task )
{
    std::lock_guard< BlockType > lock( _taskQueueMutex );
    _taskQueue.push_back( task );
    _notifyThreadsContinueCv.notify_one();
}

void ThreadPool::waitAllTaskCompleted() const
{
    std::unique_lock< BlockType > taskQueueUniqueLock( _taskQueueMutex );
    if ( !_taskQueue.empty() || _workingThreadCount.load() != 0 )
    {
        _notifyThreadComplete.wait( taskQueueUniqueLock, [ & ] {
            {
                return _taskQueue.empty() && _workingThreadCount.load() == 0;
            }
        } );
    }

    {
        std::lock_guard< BlockType > lock( _exceptionMutex );
        if ( _exception )
        {
            throw _exception;
        }
    }
}

void ThreadPool::runTask()
{
    while ( !threadsStopFlag )
    {
        std::unique_lock< BlockType > cvTaskQueueUniqueLock( _taskQueueMutex );
        try
        {
            if ( _taskQueue.empty() )
            {
                _notifyThreadsContinueCv.wait( cvTaskQueueUniqueLock,
                    [ & ]() { return !_taskQueue.empty() || threadsStopFlag; } );

                if ( threadsStopFlag )
                {
                    break;
                }
            }

            auto task = _taskQueue.front();
            _taskQueue.pop_front();

            // Увеличение атомарного счетчика нужно производить под блокировкой очереди
            // задач, чтобы учесть что задача находится в обработке
            _workingThreadCount.fetch_add( 1 );
            cvTaskQueueUniqueLock.unlock();

            task();
        }
        catch ( ... )
        {
            std::lock_guard< BlockType > lock( _exceptionMutex );
            _exception = std::current_exception();
        }

        cvTaskQueueUniqueLock.lock();
        // Необходимо выполнять под блокировкой чтобы не попасть в функции
        // waitAllTaskCompleted в промежуток между проверкой кол-ва работающих потоков и
        // ожиданием уведомлений
        _workingThreadCount.fetch_sub( 1 );
        _notifyThreadComplete.notify_one();
    }
}

} // namespace phycoub