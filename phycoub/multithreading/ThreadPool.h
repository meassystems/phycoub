#pragma once

#include <list>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>

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

    std::list< std::function< void() > > _taskQueue;
    uint32_t _threadBusyCounter = 0;
    uint32_t _availableThreadCount = 1;

    mutable std::mutex _poolMutex;
    mutable std::condition_variable _notifyThreadCompleteCv;

    mutable std::mutex _exceptionMutex;
    mutable std::exception_ptr _exception;
};

} // namespace phycoub
