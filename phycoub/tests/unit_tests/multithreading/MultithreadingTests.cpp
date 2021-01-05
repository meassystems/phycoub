#include "MultithreadingTests.h"

#include <chrono>
#include <thread>
#include <atomic>

#include "ThreadPool.h"
#include "MathExceptions.h"

using namespace phycoub;

TEST_F( MultithreadingTests, ThreadPool )
{
    bool firstTaskCalled = false;
    auto firstTask = [ & ]() {
        std::this_thread::sleep_for( std::chrono::milliseconds( 200 ) );
        firstTaskCalled = true;
    };

    bool secondTaskCalled = false;
    auto secondTask = [ & ]() {
        std::this_thread::sleep_for( std::chrono::milliseconds( 300 ) );
        secondTaskCalled = true;
    };

    ThreadPool taskPool;
    taskPool.pushTask( firstTask );
    taskPool.pushTask( secondTask );

    taskPool.waitAllTaskCompleted();

    ASSERT_TRUE( firstTaskCalled );
    ASSERT_TRUE( secondTaskCalled );
}

TEST_F( MultithreadingTests, ThreadPoolException )
{
    bool firstTaskCalled = false;
    auto firstTask = [ & ]() {
        std::this_thread::sleep_for( std::chrono::milliseconds( 200 ) );
        firstTaskCalled = true;
    };

    auto secondTask = [ & ]() { throw DivisionByZeroException(); };

    ThreadPool taskPool;
    taskPool.pushTask( secondTask );
    taskPool.pushTask( firstTask );

    EXPECT_THROW( taskPool.waitAllTaskCompleted(), std::exception_ptr );
    ASSERT_TRUE( firstTaskCalled );
}

TEST_F( MultithreadingTests, ThreadPoolStress )
{
    unsigned expectedCounterValue = 1000;

    std::atomic_uint32_t counter = {0};
    auto task = [ & ]() {
      std::chrono::milliseconds( 5 );
      counter.fetch_add(1);
    };

    for ( unsigned i = 0; i < 1000; ++i )
    {
        ThreadPool taskPool;
        for ( unsigned j = 0; j < expectedCounterValue; ++j )
        {
            taskPool.pushTask( task );
        }
        taskPool.waitAllTaskCompleted();
        ASSERT_EQ(counter.load(), expectedCounterValue);
        counter.fetch_sub(expectedCounterValue);
    }
}