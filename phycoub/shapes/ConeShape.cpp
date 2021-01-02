/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-15 22:44:23
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 23:01:21
 */

#include "ConeShape.h"

#include "math.h"

namespace phycoub
{

ConeShape::ConeShape( double height, double angle )
    : height_( height )
    , angle_( angle )
{
    updateRadius();
}

void ConeShape::setHeight( double height )
{
    height_ = height;
    updateAngle();
}

double ConeShape::getHeight() const
{
    return height_;
}

void ConeShape::setAngle( double angle )
{
    angle_ = angle;
    updateRadius();
}

double ConeShape::getAngle() const
{
    return angle_;
}

void ConeShape::setRadius( double radius )
{
    radius_ = radius;
    updateAngle();
}

double ConeShape::getRadius() const
{
    return radius_;
}

void ConeShape::updateRadius()
{
    radius_ = height_ * tan( angle_ );
}

void ConeShape::updateAngle()
{
    angle_ = atan2( radius_, height_ );
}

} // namespace phycoub