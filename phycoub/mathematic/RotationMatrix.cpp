/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-10 18:40:46
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-30 09:44:31
 */

#include "RotationMatrix.h"

#ifdef defined(DARWIN)
#   include <cmath>
#elif defined(WIN32)
#   define _USE_MATH_DEFINES
#   include <math.h>
#endif

#include "VectorUtils.h"
#include "ProgrammingException.h"

namespace phycoub
{

using namespace std;

RotationMatrix::RotationMatrix( const Vector& rotation )
{
    PROGRAMMING_ASSERT( rotation.x_ <= abs( 2 * M_PI ) && rotation.y_ <= abs( 2 * M_PI )
        && rotation.z_ <= abs( 2 * M_PI ) );

    initMatrix( rotation );
}

void RotationMatrix::rotateVector( Vector* vector )
{
    *vector = matrix_ * *vector;
}

void RotationMatrix::initMatrix( const Vector& rotation )
{
    double cosAlpha = cos( rotation.z_ );
    double sinAlpha = sin( rotation.z_ );

    double cosBeta = cos( rotation.y_ );
    double sinBeta = sin( rotation.y_ );

    double cosGamma = cos( rotation.x_ );
    double sinGamma = sin( rotation.x_ );

    matrix_[ 0 ] = cosAlpha * cosBeta;
    matrix_[ 3 ] = sinAlpha * cosBeta;
    matrix_[ 6 ] = -1 * sinBeta;

    matrix_[ 1 ] = cosAlpha * sinBeta * sinGamma - sinAlpha * cosGamma;
    matrix_[ 4 ] = sinAlpha * sinBeta * sinGamma + cosAlpha * cosGamma;
    matrix_[ 7 ] = cosBeta * sinGamma;

    matrix_[ 2 ] = cosAlpha * sinBeta * cosGamma + sinAlpha * sinGamma;
    matrix_[ 5 ] = sinAlpha * sinBeta * cosGamma - cosAlpha * sinGamma;
    matrix_[ 8 ] = cosBeta * cosGamma;
}

// static
Vector RotationMatrix::directionToRotation( const Vector& direction )
{
    const Vector directionN = VectorUtils::normalizeVector( direction );

    double thetaRad = ( directionN.z_ == 0
            ? signbit( directionN.z_ ) ? -M_PI_2 : M_PI_2
            : atan( sqrt( pow( directionN.x_, 2 ) + pow( directionN.y_, 2 ) )
                / directionN.z_ ) );

    const double thetaRadAbs = M_PI_2 - abs( thetaRad );
    thetaRad = signbit( thetaRad ) ? thetaRadAbs : -1 * thetaRadAbs;

    double alphaRad = directionN.x_ == 0
        ? signbit( directionN.x_ * directionN.y_ ) ? -M_PI_2 : M_PI_2
        : atan( directionN.y_ / directionN.x_ );

    const double alphaRadAbs = abs( alphaRad );
    if ( !signbit( directionN.x_ ) )
    {
        if ( signbit( directionN.y_ ) )
        {
            alphaRad = 2. * M_PI - alphaRadAbs;
        }
    }
    else
    {
        if ( !signbit( directionN.y_ ) )
        {
            alphaRad = M_PI - alphaRadAbs;
        }
        else
        {
            alphaRad = M_PI + alphaRadAbs;
        }
    }

    return Vector{ 0., thetaRad, alphaRad };
}

} // namespace phycoub