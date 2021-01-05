#pragma once

#include <list>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <atomic>

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

    std::list< std::thread > threads;
    bool threadsStopFlag = false;
    std::atomic_uint32_t _workingThreadCount = { 0 };

    mutable std::mutex _taskQueueMutex;
    mutable std::condition_variable _notifyThreadsContinueCv;
    mutable std::condition_variable _notifyThreadComplete;
    std::list< std::function< void() > > _taskQueue;

    mutable std::mutex _exceptionMutex;
    mutable std::exception_ptr _exception;
};

} // namespace phycoub
