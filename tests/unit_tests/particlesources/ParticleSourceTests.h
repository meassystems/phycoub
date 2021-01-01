#include "gtest/gtest.h"

class ParticleSourceTests : public ::testing::Test
{
  protected:
    ParticleSourceTests() = default;
    virtual ~ParticleSourceTests() override = default;

    static constexpr double doubleComparePrecision = 1e-15;
};