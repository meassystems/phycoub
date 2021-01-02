#include "ParticleSourceTests.h"

#include <math.h>

#include "ConeParticleSource.h"

using namespace phycoub;

TEST_F( ParticleSourceTests, ConeParticleSourceTest )
{
    {
        const Vector direction{ 0., 0., 1. };
        const double angle = 0.;
        const Vector sourceCoordinate{ 1., 1., 1. };
        const ParticleOptions particleOptions{ 1., 1. };
        const double energy = 2.;

        ConeParticleSource coneParticleSource{ direction, angle, sourceCoordinate,
            particleOptions, energy };
        ParticlePtr particle = coneParticleSource.phyGiveBirthParticle();
        Vector v = particle->getSpeed();

        Vector expectedResult{ 0., 0., 2. };
        ASSERT_NEAR( v.x_, expectedResult.x_, doubleComparePrecision );
        ASSERT_NEAR( v.y_, expectedResult.y_, doubleComparePrecision );
        ASSERT_NEAR( v.z_, expectedResult.z_, doubleComparePrecision );
    }

    {
        const Vector direction{ 0., 1., 1. };
        const double angle = 0.;
        const Vector sourceCoordinate{ 1., 1., 1. };
        const ParticleOptions particleOptions{ 1., 1. };
        const double energy = 2.;

        ConeParticleSource coneParticleSource{ direction, angle, sourceCoordinate,
            particleOptions, energy };
        ParticlePtr particle = coneParticleSource.phyGiveBirthParticle();
        Vector v = particle->getSpeed();

        double normalizedVectorComponent = sqrt( 0.5 );
        Vector expectedResult{ 0., 2. * normalizedVectorComponent,
            2. * normalizedVectorComponent };
        ASSERT_NEAR( v.x_, expectedResult.x_, doubleComparePrecision );
        ASSERT_NEAR( v.y_, expectedResult.y_, doubleComparePrecision );
        ASSERT_NEAR( v.z_, expectedResult.z_, doubleComparePrecision );
    }
}