#pragma once

#include <list>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <atomic>

#include "SpinLock.h"

namespace phycoub
{

class ThreadPool final
{
  public:
    ThreadPool();
    ~ThreadPool();

    void pushTask( std::function< void() > task );
    void waitAllTaskCompleted() const;

  private:
    void runTask();

    using BlockType = SpinLock;

    std::list< std::thread > threads;
    bool threadsStopFlag = false;
    std::atomic_uint32_t _workingThreadCount = { 0 };

    mutable BlockType _taskQueueMutex;
    mutable std::condition_variable_any _notifyThreadsContinueCv;
    mutable std::condition_variable_any _notifyThreadComplete;
    std::list< std::function< void() > > _taskQueue;

    mutable BlockType _exceptionMutex;
    mutable std::exception_ptr _exception;
};

} // namespace phycoub
