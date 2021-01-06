#include "MathematicTests.h"

#if defined( DARWIN )
#    include <cmath>
#elif defined( WIN32 )
#    define _USE_MATH_DEFINES
#    include <math.h>
#endif

#include "RotationMatrix.h"
#include "VectorUtils.h"

using namespace phycoub;

TEST_F( MathematicTests, MatrixMultiplicationVector )
{
    Matrix a = { 1., 2., 3., 4., 5., 6., 7., 8., 9. };
    Vector b{ 1. };

    Vector result = a * b;
    Vector expectedResult{ 6., 15., 24. };

    ASSERT_EQ( result, expectedResult );
}

TEST_F( MathematicTests, VectorMultiplicationMatrix )
{
    Matrix a = { 1., 2., 3., 4., 5., 6., 7., 8., 9. };
    Vector b{ 1. };

    Vector result = b * a;
    Vector expectedResult{ 12., 15., 18. };

    ASSERT_EQ( result, expectedResult );
}

TEST_F( MathematicTests, VectorVectorMultiplication )
{
    Vector a{ 1. };
    Vector b{ 1., 2., 3. };

    Vector result = a * b;
    Vector expectedResult{ 1., -2., 1. };

    ASSERT_EQ( result, expectedResult );
}

TEST_F( MathematicTests, RotationMatrixAroundX )
{
    {
        Vector v{ 1., 0., 1. };
        RotationMatrix xRotation{ Vector{ M_PI_2, 0., 0. } };
        xRotation.rotateVector( &v );

        Vector expectedResult{ 1., -1., 0. };
        ASSERT_NEAR( v.x_, expectedResult.x_, doubleComparePrecision );
        ASSERT_NEAR( v.y_, expectedResult.y_, doubleComparePrecision );
        ASSERT_NEAR( v.z_, expectedResult.z_, doubleComparePrecision );
    }

    {
        Vector v{ 1., 0., 1. };
        RotationMatrix xRotation{ Vector{ -1 * M_PI_2, 0., 0. } };
        xRotation.rotateVector( &v );

        Vector expectedResult{ 1., 1., 0. };
        ASSERT_NEAR( v.x_, expectedResult.x_, doubleComparePrecision );
        ASSERT_NEAR( v.y_, expectedResult.y_, doubleComparePrecision );
        ASSERT_NEAR( v.z_, expectedResult.z_, doubleComparePrecision );
    }

    {
        Vector v{ 1., 0., 1. };
        RotationMatrix xRotation{ Vector{ M_PI, 0., 0. } };
        xRotation.rotateVector( &v );

        Vector expectedResult{ 1., 0., -1. };
        ASSERT_NEAR( v.x_, expectedResult.x_, doubleComparePrecision );
        ASSERT_NEAR( v.y_, expectedResult.y_, doubleComparePrecision );
        ASSERT_NEAR( v.z_, expectedResult.z_, doubleComparePrecision );
    }

    {
        Vector v{ 1., 0., 1. };
        RotationMatrix xRotation{ Vector{ -1 * M_PI, 0., 0. } };
        xRotation.rotateVector( &v );

        Vector expectedResult{ 1., 0., -1. };
        ASSERT_NEAR( v.x_, expectedResult.x_, doubleComparePrecision );
        ASSERT_NEAR( v.y_, expectedResult.y_, doubleComparePrecision );
        ASSERT_NEAR( v.z_, expectedResult.z_, doubleComparePrecision );
    }

    {
        Vector v{ 1., 0., 1. };
        RotationMatrix xRotation{ Vector{ 0, 0., 0. } };
        xRotation.rotateVector( &v );

        Vector expectedResult{ 1., 0., 1. };
        ASSERT_NEAR( v.x_, expectedResult.x_, doubleComparePrecision );
        ASSERT_NEAR( v.y_, expectedResult.y_, doubleComparePrecision );
        ASSERT_NEAR( v.z_, expectedResult.z_, doubleComparePrecision );
    }

    {
        Vector v{ 1., 0., 1. };
        RotationMatrix xRotation{ Vector{ 2 * M_PI, 0., 0. } };
        xRotation.rotateVector( &v );

        Vector expectedResult{ 1., 0., 1. };
        ASSERT_NEAR( v.x_, expectedResult.x_, doubleComparePrecision );
        ASSERT_NEAR( v.y_, expectedResult.y_, doubleComparePrecision );
        ASSERT_NEAR( v.z_, expectedResult.z_, doubleComparePrecision );
    }
}

TEST_F( MathematicTests, RotationMatrixAroundY )
{
    {
        Vector v{ 1., 1., 0. };
        RotationMatrix xRotation{ Vector{ 0., M_PI_2, 0. } };
        xRotation.rotateVector( &v );

        Vector expectedResult{ 0., 1., -1. };
        ASSERT_NEAR( v.x_, expectedResult.x_, doubleComparePrecision );
        ASSERT_NEAR( v.y_, expectedResult.y_, doubleComparePrecision );
        ASSERT_NEAR( v.z_, expectedResult.z_, doubleComparePrecision );
    }

    {
        Vector v{ 1., 1., 0. };
        RotationMatrix xRotation{ Vector{ 0., -1 * M_PI_2, 0. } };
        xRotation.rotateVector( &v );

        Vector expectedResult{ 0., 1., 1. };
        ASSERT_NEAR( v.x_, expectedResult.x_, doubleComparePrecision );
        ASSERT_NEAR( v.y_, expectedResult.y_, doubleComparePrecision );
        ASSERT_NEAR( v.z_, expectedResult.z_, doubleComparePrecision );
    }

    {
        Vector v{ 1., 1., 0. };
        RotationMatrix xRotation{ Vector{ 0., M_PI, 0. } };
        xRotation.rotateVector( &v );

        Vector expectedResult{ -1., 1., 0. };
        ASSERT_NEAR( v.x_, expectedResult.x_, doubleComparePrecision );
        ASSERT_NEAR( v.y_, expectedResult.y_, doubleComparePrecision );
        ASSERT_NEAR( v.z_, expectedResult.z_, doubleComparePrecision );
    }

    {
        Vector v{ 1., 1., 0. };
        RotationMatrix xRotation{ Vector{ 0., -1 * M_PI, 0. } };
        xRotation.rotateVector( &v );

        Vector expectedResult{ -1., 1., 0. };
        ASSERT_NEAR( v.x_, expectedResult.x_, doubleComparePrecision );
        ASSERT_NEAR( v.y_, expectedResult.y_, doubleComparePrecision );
        ASSERT_NEAR( v.z_, expectedResult.z_, doubleComparePrecision );
    }

    {
        Vector v{ 1., 1., 0. };
        RotationMatrix xRotation{ Vector{ 0, 0., 0. } };
        xRotation.rotateVector( &v );

        Vector expectedResult{ 1., 1., 0. };
        ASSERT_NEAR( v.x_, expectedResult.x_, doubleComparePrecision );
        ASSERT_NEAR( v.y_, expectedResult.y_, doubleComparePrecision );
        ASSERT_NEAR( v.z_, expectedResult.z_, doubleComparePrecision );
    }

    {
        Vector v{ 1., 1., 0. };
        RotationMatrix xRotation{ Vector{ 2 * M_PI, 0., 0. } };
        xRotation.rotateVector( &v );

        Vector expectedResult{ 1., 1., 0. };
        ASSERT_NEAR( v.x_, expectedResult.x_, doubleComparePrecision );
        ASSERT_NEAR( v.y_, expectedResult.y_, doubleComparePrecision );
        ASSERT_NEAR( v.z_, expectedResult.z_, doubleComparePrecision );
    }
}

TEST_F( MathematicTests, RotationMatrixAroundZ )
{
    {
        Vector v{ 0., 1., 1. };
        RotationMatrix xRotation{ Vector{ 0., 0., M_PI_2 } };
        xRotation.rotateVector( &v );

        Vector expectedResult{ -1., 0., 1. };
        ASSERT_NEAR( v.x_, expectedResult.x_, doubleComparePrecision );
        ASSERT_NEAR( v.y_, expectedResult.y_, doubleComparePrecision );
        ASSERT_NEAR( v.z_, expectedResult.z_, doubleComparePrecision );
    }

    {
        Vector v{ 0., 1., 1. };
        RotationMatrix xRotation{ Vector{ 0., 0., -1 * M_PI_2 } };
        xRotation.rotateVector( &v );

        Vector expectedResult{ 1., 0., 1. };
        ASSERT_NEAR( v.x_, expectedResult.x_, doubleComparePrecision );
        ASSERT_NEAR( v.y_, expectedResult.y_, doubleComparePrecision );
        ASSERT_NEAR( v.z_, expectedResult.z_, doubleComparePrecision );
    }

    {
        Vector v{ 0., 1., 1. };
        RotationMatrix xRotation{ Vector{ 0., 0., M_PI } };
        xRotation.rotateVector( &v );

        Vector expectedResult{ 0., -1., 1. };
        ASSERT_NEAR( v.x_, expectedResult.x_, doubleComparePrecision );
        ASSERT_NEAR( v.y_, expectedResult.y_, doubleComparePrecision );
        ASSERT_NEAR( v.z_, expectedResult.z_, doubleComparePrecision );
    }

    {
        Vector v{ 0., 1., 1. };
        RotationMatrix xRotation{ Vector{ 0., 0., -1 * M_PI } };
        xRotation.rotateVector( &v );

        Vector expectedResult{ 0., -1., 1. };
        ASSERT_NEAR( v.x_, expectedResult.x_, doubleComparePrecision );
        ASSERT_NEAR( v.y_, expectedResult.y_, doubleComparePrecision );
        ASSERT_NEAR( v.z_, expectedResult.z_, doubleComparePrecision );
    }

    {
        Vector v{ 0., 1., 1. };
        RotationMatrix xRotation{ Vector{ 0, 0., 0. } };
        xRotation.rotateVector( &v );

        Vector expectedResult{ 0., 1., 1. };
        ASSERT_NEAR( v.x_, expectedResult.x_, doubleComparePrecision );
        ASSERT_NEAR( v.y_, expectedResult.y_, doubleComparePrecision );
        ASSERT_NEAR( v.z_, expectedResult.z_, doubleComparePrecision );
    }

    {
        Vector v{ 0., 1., 1. };
        RotationMatrix xRotation{ Vector{ 0., 0., 2 * M_PI } };
        xRotation.rotateVector( &v );

        Vector expectedResult{ 0., 1., 1. };
        ASSERT_NEAR( v.x_, expectedResult.x_, doubleComparePrecision );
        ASSERT_NEAR( v.y_, expectedResult.y_, doubleComparePrecision );
        ASSERT_NEAR( v.z_, expectedResult.z_, doubleComparePrecision );
    }
}

TEST_F( MathematicTests, RotationMatrixAround )
{
    {
        Vector v{ 1., 0., 0. };
        RotationMatrix rotation{ Vector{ 0., -M_PI_2, M_PI_2 } };
        rotation.rotateVector( &v );

        Vector expectedResult{ 0., 0., 1. };
        ASSERT_NEAR( v.x_, expectedResult.x_, doubleComparePrecision );
        ASSERT_NEAR( v.y_, expectedResult.y_, doubleComparePrecision );
        ASSERT_NEAR( v.z_, expectedResult.z_, doubleComparePrecision );
    }

    {
        Vector v{ 1., 0., 0. };
        RotationMatrix rotation{ Vector{ 0., -M_PI_4, M_PI_2 } };
        rotation.rotateVector( &v );

        const double normalizedVectorProjection = sqrt( 0.5 );
        Vector expectedResult{ 0., normalizedVectorProjection,
            normalizedVectorProjection };
        ASSERT_NEAR( v.x_, expectedResult.x_, doubleComparePrecision );
        ASSERT_NEAR( v.y_, expectedResult.y_, doubleComparePrecision );
        ASSERT_NEAR( v.z_, expectedResult.z_, doubleComparePrecision );
    }
}

TEST_F( MathematicTests, VectorUtilsCalculatePerpendicular )
{
    Vector expectedResult{ 1., 0., 0. };

    const Vector n{ 0., 0., 1. };
    const Vector v{ 0., 1., 0. };

    const Vector u = VectorUtils::calculatePerpendicular( n, v );
    ASSERT_NEAR( u.x_, expectedResult.x_, doubleComparePrecision );
    ASSERT_NEAR( u.y_, expectedResult.y_, doubleComparePrecision );
    ASSERT_NEAR( u.z_, expectedResult.z_, doubleComparePrecision );
}