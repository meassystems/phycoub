#include "ParticleTests.h"

#include <list>

#include "ParticleGroupList.h"

using namespace phycoub;

TEST_F( ParticleTests, ParticleGroupTest )
{
    const Vector coordinate{ 0. };
    const Vector speed{ 0. };
    const ParticleOptions options{ 1., 1. };

    std::list< IDType > idVector;
    ParticleGroup particleGroup;

    for ( uint8_t i = 0; i < 10; ++i )
    {
        ParticlePtr particle = std::make_shared< Particle >( coordinate, speed, options );
        idVector.push_back( particle->getId() );
        particleGroup.push_back( particle );
    }

    for ( ParticlePtr particle : particleGroup )
    {
        auto idItr = std::find( idVector.begin(), idVector.end(), particle->getId() );
        if ( idItr == idVector.end() )
        {
            FAIL();
        }

        idVector.erase( idItr );
    }

    ASSERT_EQ( idVector.size(), 0 );
}

TEST_F( ParticleTests, ParticleGroupListTest )
{
    const Vector coordinate{ 0. };
    const Vector speed{ 0. };
    const ParticleOptions options{ 1., 1. };

    std::list< IDType > idVector;

    ParticleGroupPtr particleGroup1 = std::make_shared< ParticleGroup >();
    for ( uint8_t i = 0; i < 10; ++i )
    {
        ParticlePtr particle = std::make_shared< Particle >( coordinate, speed, options );
        idVector.push_back( particle->getId() );
        particleGroup1->push_back( particle );
    }

    ParticleGroupPtr particleGroup2 = std::make_shared< ParticleGroup >();
    for ( uint8_t i = 0; i < 5; ++i )
    {
        ParticlePtr particle = std::make_shared< Particle >( coordinate, speed, options );
        idVector.push_back( particle->getId() );
        particleGroup2->push_back( particle );
    }

    ParticleGroupList particleGroupList;
    particleGroupList.push_back( particleGroup1 );
    particleGroupList.push_back( particleGroup2 );

    particleGroupList.forEachParticle( [ & ]( ParticlePtr particle ) {
        auto idItr = std::find( idVector.begin(), idVector.end(), particle->getId() );
        if ( idItr == idVector.end() )
        {
            FAIL();
        }

        idVector.erase( idItr );
    } );

    ASSERT_EQ( idVector.size(), 0 );
}