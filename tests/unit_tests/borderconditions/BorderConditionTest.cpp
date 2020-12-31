#include "BorderConditionTests.h"

#include "BorderCondition.h"

using namespace phycoub;

TEST_F(BorderConditionTests, BorderConditionTest) {
    Vector move{10., 10., 10.};
    Vector speed{1., 1., 1.};
    ParticlePtr particle = std::make_shared<Particle>(Vector{0., 0., 0.}, Vector{0., 0., 0.}, 0., 0. );

    BorderCondition borderCondition;
    borderCondition.psyMove(move, speed, particle);

    ASSERT_EQ(particle->getCoordinate(), move);
    ASSERT_EQ(particle->getSpeed(), speed);
}