#pragma once

#include <atomic>

namespace phycoub
{

class SpinLock final
{
  public:
    SpinLock() = default;
    ~SpinLock() = default;

    SpinLock( const SpinLock& ) = delete;
    SpinLock& operator=( const SpinLock& ) = delete;

    SpinLock( SpinLock&& ) = delete;
    SpinLock& operator=( SpinLock&& ) = delete;

    // BasicLockable
    // https://en.cppreference.com/w/cpp/named_req/BasicLockable
    void lock();
    void unlock();

    // Lockable
    // https://en.cppreference.com/w/cpp/named_req/Lockable
    bool try_lock();

  private:
    std::atomic_flag _atomicFlag = ATOMIC_FLAG_INIT;
};

} // namespace phycoub