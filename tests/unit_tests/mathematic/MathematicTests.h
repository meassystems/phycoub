#include "gtest/gtest.h"

class MathematicTests : public ::testing::Test
{
  protected:
    MathematicTests() = default;
    virtual ~MathematicTests() override = default;

    static constexpr double doubleComparePrecision = 1e-15;
};