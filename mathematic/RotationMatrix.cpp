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

RotationMatrix::RotationMatrix( const Vector& cosines )
{
    setRotationCosines( cosines );
}

void RotationMatrix::setRotationCosines( const Vector& cosines )
{
    PROGRAMMING_ASSERT(
        abs( cosines.x_ ) <= 1 && abs( cosines.y_ ) <= 1 && abs( cosines.z_ ) <= 1 );

    cosines_ = cosines;

    sinuses_ = Vector{ sqrt( 1 - pow( cosines_.x_, 2 ) ),
        sqrt( 1 - pow( cosines_.y_, 2 ) ), sqrt( 1 - pow( cosines_.z_, 2 ) ) };

    updateMatrix( cosines_, sinuses_ );
}

void RotationMatrix::setRotationSinuses( const Vector& sinuses )
{
    sinuses_ = sinuses;
    updateMatrix( cosines_, sinuses_ );
}

void RotationMatrix::rotateVector( Vector* vector )
{
    *vector = matrix_ * *vector;
}

void RotationMatrix::updateMatrix( const Vector& cosines, const Vector& sinuses )
{
    matrix_[ 0 ] = cosines.y_ * cosines.z_;
    matrix_[ 3 ] = sinuses.z_;
    matrix_[ 6 ] = -1 * sinuses.y_ * cosines.z_;

    matrix_[ 1 ] = sinuses.y_ * sinuses.x_ - cosines.y_ * sinuses.z_ * cosines.x_;
    matrix_[ 4 ] = cosines.z_ * cosines.x_;
    matrix_[ 7 ] = sinuses.y_ * sinuses.z_ * cosines.x_ + cosines.y_ * sinuses.x_;

    matrix_[ 2 ] = cosines.y_ * sinuses.z_ * sinuses.x_ + sinuses.y_ * cosines.x_;
    matrix_[ 5 ] = -1 * cosines.z_ * sinuses.x_;
    matrix_[ 8 ] = cosines.y_ * cosines.x_ - sinuses.y_ * sinuses.z_ * sinuses.x_;
}

} // namespace phycoub