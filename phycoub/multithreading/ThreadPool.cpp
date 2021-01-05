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
    _taskQueue.push_back( task );

    if ( _threadBusyCounter < _availableThreadCount )
    {
        std::thread thread( &ThreadPool::runTask, this );
        thread.detach();
        ++_threadBusyCounter;
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

void ThreadPool::runTask()
{
    try
    {
        std::unique_lock< std::mutex > lock( _poolMutex );
        while ( true )
        {
            if ( _taskQueue.size() == 0 )
            {
                --_threadBusyCounter;
                lock.unlock();
                _notifyThreadCompleteCv.notify_all();
                break;
            }

            std::function< void() > task = _taskQueue.front();
            _taskQueue.pop_front();

            lock.unlock();
            task();
            lock.lock();
        }
    }
    catch ( ... )
    {
        std::lock_guard< std::mutex > lock( _exceptionMutex );
        _exception = std::current_exception();
    }
}

} // namespace phycoub