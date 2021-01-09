#include "gtest/gtest.h"

class LinearAlgebraEquationTests : public ::testing::Test
{
  protected:
    LinearAlgebraEquationTests() = default;
    virtual ~LinearAlgebraEquationTests() override = default;

    static constexpr double doubleComparePrecision = 1e-15;
};