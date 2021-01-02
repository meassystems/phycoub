#include "BorderConditionTests.h"
#include "BorderReachedObserverMock.h"

#include "BorderCondition.h"
#include "CyclicBorder.h"
#include "CylinderBorderCondition.h"
#include "ElasticCoubCondition.h"

using namespace phycoub;

TEST_F( BorderConditionTests, BorderConditionTest )
{
    Vector move{ 10., 10., 10. };
    Vector speed{ 1., 1., 1. };
    ParticlePtr particle = std::make_shared< Particle >(
        Vector{ 0., 0., 0. }, Vector{ 0., 0., 0. }, 0., 0. );

    BorderCondition borderCondition;
    borderCondition.psyMove( move, speed, particle );

    ASSERT_EQ( particle->getCoordinate(), move );
}

TEST_F( BorderConditionTests, CyclicBorder )
{
    Vector move{ 10., 10., 10. };
    Vector speed{ 1., 1., 1. };
    ParticlePtr particle = std::make_shared< Particle >(
        Vector{ 0., 0., 0. }, Vector{ 0., 0., 0. }, 0., 0. );

    Vector borders{ 7., 7., 7. };
    CyclicBorder cyclicBorder{ borders };
    cyclicBorder.psyMove( move, speed, particle );

    ASSERT_EQ( particle->getCoordinate(), move - borders );
}

TEST_F( BorderConditionTests, CylinderBorderCondition )
{
    std::shared_ptr< BorderReachedObserverMock > borderReachedObserver
        = std::make_shared< BorderReachedObserverMock >();

    Vector move{ 10., 10., 0. };
    Vector speed{ 1., 1., 1. };
    ParticlePtr particle = std::make_shared< Particle >(
        Vector{ 0., 0., 0. }, Vector{ 0., 0., 0. }, 0., 0. );

    EXPECT_CALL( *borderReachedObserver, onBorderReached( particle ) ).Times( 1 );

    CylinderBorderCondition cylinderBorderCondition{ 4., 2. };
    cylinderBorderCondition.addBorderReachedObserver( borderReachedObserver );
    cylinderBorderCondition.psyMove( move, speed, particle );

    ASSERT_EQ( particle->getSpeed(), speed );
}

TEST_F( BorderConditionTests, ElasticCoubCondition )
{
    Vector move{ 10., 10., 10. };
    Vector speed{ 1., 1., 1. };
    ParticlePtr particle = std::make_shared< Particle >(
        Vector{ 0., 0., 0. }, Vector{ 0., 0., 0. }, 0., 0. );

    Vector borders{ 7., 7., 7. };
    ElasticCoubCondition elasticBorder{ borders };
    elasticBorder.psyMove( move, speed, particle );

    ASSERT_EQ( particle->getCoordinate(), borders - move + borders );
}