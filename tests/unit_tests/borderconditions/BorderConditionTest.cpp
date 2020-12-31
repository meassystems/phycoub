#include "BorderCondition.h"
#include "BorderConditionTests.h"


FooTest::FooTest() {
}

FooTest::~FooTest() {};

void FooTest::SetUp() {};

void FooTest::TearDown() {};

TEST_F(FooTest, ByDefaultBazTrueIsTrue1) {
    EXPECT_EQ(true, true);
}

TEST_F(FooTest, ByDefaultBazTrueIsTrue2) {
EXPECT_EQ(false, true);
}