#include "gtest/gtest.h"

// The fixture for testing class Foo.
class LifeTimeControllerTests : public ::testing::Test
{
  protected:
    LifeTimeControllerTests() = default;
    virtual ~LifeTimeControllerTests() override = default;
};