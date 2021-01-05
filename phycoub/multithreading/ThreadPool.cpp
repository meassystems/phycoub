#include "ThreadPool.h"

#include <thread>
#include <exception>

namespace phycoub
{

ThreadPool::ThreadPool()
{
    _availableThreadCount = std::thread::hardware_concurrency();
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
}

void ThreadPool::pushTask( std::function< void() > task )
{
    std::lock_guard< std::mutex > lock( _poolMutex );

    if ( _threadBusyCounter < _availableThreadCount )
    {
        std::thread thread( &ThreadPool::runTask, this, task );
        thread.detach();
        ++_threadBusyCounter;
    }
    else
    {
        _taskQueue.push_back( task );
    }
}

void ThreadPool::waitAllTaskCompleted() const
{
    std::unique_lock< std::mutex > cvUniqueLock( _poolMutex );
    if ( _taskQueue.size() != 0 || _threadBusyCounter != 0 )
    {
        _notifyThreadCompleteCv.wait( cvUniqueLock, [ & ] {
            {
                return _taskQueue.size() == 0 && _threadBusyCounter == 0;
            }
        } );
    }

    {
        std::lock_guard< std::mutex > lock( _exceptionMutex );
        if ( _exception )
        {
            throw _exception;
        }
    }
}

void ThreadPool::runTask( std::function< void() > task )
{
    try
    {
        task();
    }
    catch ( ... )
    {
        std::lock_guard< std::mutex > lock( _exceptionMutex );
        _exception = std::current_exception();
    }

    {
        std::unique_lock< std::mutex > lock( _poolMutex );
        if ( _taskQueue.size() > 0 )
        {
            std::function< void() > task = _taskQueue.front();
            std::thread thread( &ThreadPool::runTask, this, task );
            thread.detach();
            _taskQueue.pop_front();
        }
        else
        {
            --_threadBusyCounter;
            lock.unlock();
            _notifyThreadCompleteCv.notify_all();
        }
    }
}

} // namespace phycoub