#include "MultithreadingTests.h"

#include <chrono>
#include <thread>

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
    taskPool.pushTask( firstTask );
    taskPool.pushTask( secondTask );

    EXPECT_THROW( taskPool.waitAllTaskCompleted(), std::exception_ptr );
    ASSERT_TRUE( firstTaskCalled );
}