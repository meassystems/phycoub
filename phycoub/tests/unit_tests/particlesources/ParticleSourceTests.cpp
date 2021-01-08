#include "ParticleSourceTests.h"

#if defined(DARWIN)
#   include <cmath>
#elif defined(WIN32)
#   define _USE_MATH_DEFINES
#   include <math.h>
#endif

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
        ASSERT_NEAR( v.x(), expectedResult.x(), doubleComparePrecision );
        ASSERT_NEAR( v.y(), expectedResult.y(), doubleComparePrecision );
        ASSERT_NEAR( v.z(), expectedResult.z(), doubleComparePrecision );
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
        ASSERT_NEAR( v.x(), expectedResult.x(), doubleComparePrecision );
        ASSERT_NEAR( v.y(), expectedResult.y(), doubleComparePrecision );
        ASSERT_NEAR( v.z(), expectedResult.z(), doubleComparePrecision );
    }
}