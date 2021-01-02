/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-10 18:40:46
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-30 09:44:31
 */

#include "RotationMatrix.h"

#include <math.h>

#include "ProgrammingException.h"

namespace phycoub
{

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

} // namespace phycoub