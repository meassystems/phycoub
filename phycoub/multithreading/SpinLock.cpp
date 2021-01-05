#include "SpinLock.h"

namespace phycoub
{

void SpinLock::lock()
{
    while ( _atomicFlag.test_and_set( std::memory_order_acquire ) )
        ;
}

void SpinLock::unlock()
{
    _atomicFlag.clear( std::memory_order_release );
}

bool SpinLock::try_lock()
{
    return _atomicFlag.test_and_set( std::memory_order_acquire );
}

} // namespace phycoub