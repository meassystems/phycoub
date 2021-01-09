#include "LinearAlgebraEquationTests.h"

#include "LinearAlgebraEquationUtils.h"

using namespace phycoub;

TEST_F( LinearAlgebraEquationTests, FindStraightLineAndPlaneIntersectionPoint )
{

    PlaneEquation plane{ 0., 0., 1., -1. };
    StraightLineEquation straightLine{ { 1., 0., 0., -.5 }, { 0., 1., 0., -.5 } };
    Vector result = LinearAlgebraEquationUtils::findStraightLineAndPlaneIntersectionPoint(
        straightLine, plane ).result;

    Vector expectedResult{ .5, .5, 1. };
    ASSERT_NEAR( result.x(), expectedResult.x(), doubleComparePrecision );
    ASSERT_NEAR( result.y(), expectedResult.y(), doubleComparePrecision );
    ASSERT_NEAR( result.z(), expectedResult.z(), doubleComparePrecision );
}