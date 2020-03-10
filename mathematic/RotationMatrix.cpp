/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-10 18:40:46
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-10 19:21:59
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
    double x
        = vector->x_ * column1_.x_ + vector->y_ * column1_.y_ + -vector->z_ * column1_.z_;

    double y
        = vector->x_ * column2_.x_ + vector->y_ * column2_.y_ + -vector->z_ * column2_.z_;

    double z
        = vector->x_ * column3_.x_ + vector->y_ * column3_.y_ + -vector->z_ * column3_.z_;

    vector->x_ = x;
    vector->y_ = y;
    vector->z_ = z;
} // namespace phycoub

void RotationMatrix::updateMatrix()
{
    Vector sinuses = Vector{ sqrt( 1 - pow( guideCosines_.x_, 2 ) ),
        sqrt( 1 - pow( guideCosines_.y_, 2 ) ), sqrt( 1 - pow( guideCosines_.z_, 2 ) ) };

    column1_ = { guideCosines_.y_ * guideCosines_.z_, sinuses.z_,
        -1 * sinuses.y_ * guideCosines_.z_ };

    column2_ = {
        sinuses.y_ * sinuses.x_ - guideCosines_.y_ * sinuses.z_ * guideCosines_.x_,
        guideCosines_.z_ * guideCosines_.x_,
        sinuses.y_ * sinuses.z_ * guideCosines_.x_ + guideCosines_.y_ * guideCosines_.x_
    };

    column3_ = { guideCosines_.y_ * sinuses.z_ * sinuses.x_
            + sinuses.y_ * guideCosines_.x_,
        -1 * guideCosines_.z_ * sinuses.x_,
        guideCosines_.y_ * guideCosines_.x_ - sinuses.y_ * sinuses.z_ * sinuses.x_ };
}

} // namespace phycoub