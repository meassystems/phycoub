/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-10 18:40:46
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 01:31:40
 */

#include "RotationMatrix.h"

#include <math.h>

#include "VectorUtils.h"

namespace phycoub
{

RotationMatrix::RotationMatrix( const Vector& theGuideCosines )
{
    setGuideCosines( theGuideCosines );
}

void RotationMatrix::setGuideCosines( const Vector& theGuideCosines )
{
    guideCosines_ = VectorUtils::normalizeVector( theGuideCosines );
    updateMatrix();
}

void RotationMatrix::rotateVector( Vector* vector )
{
    *vector = *vector * matrix_;
}

void RotationMatrix::updateMatrix()
{
    Vector sinuses = Vector{ sqrt( 1 - pow( guideCosines_.x_, 2 ) ),
        sqrt( 1 - pow( guideCosines_.y_, 2 ) ), sqrt( 1 - pow( guideCosines_.z_, 2 ) ) };

    matrix_[ 0 ] = guideCosines_.y_ * guideCosines_.z_;
    matrix_[ 3 ] = sinuses.z_;
    matrix_[ 6 ] = -1 * sinuses.y_ * guideCosines_.z_;

    matrix_[ 1 ]
        = sinuses.y_ * sinuses.x_ - guideCosines_.y_ * sinuses.z_ * guideCosines_.x_;
    matrix_[ 4 ] = guideCosines_.z_ * guideCosines_.x_;
    matrix_[ 7 ] = sinuses.y_ * sinuses.z_ * guideCosines_.x_
        + guideCosines_.y_ * guideCosines_.x_;

    matrix_[ 2 ]
        = guideCosines_.y_ * sinuses.z_ * sinuses.x_ + sinuses.y_ * guideCosines_.x_;
    matrix_[ 5 ] = -1 * guideCosines_.z_ * sinuses.x_;
    matrix_[ 8 ]
        = guideCosines_.y_ * guideCosines_.x_ - sinuses.y_ * sinuses.z_ * sinuses.x_;
}

} // namespace phycoub