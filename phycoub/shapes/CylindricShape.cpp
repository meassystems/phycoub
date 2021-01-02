/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-05 01:58:23
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-05 02:04:04
 */

#include "CylindricShape.h"

#include <math.h>

namespace phycoub
{

CylindricShape::CylindricShape( double radius, double height )
    : radius_( radius )
    , height_( height )
{
    doubleRadius_ = 2 * radius_;
    squaredRadius_ = pow( radius_, 2 );
}

void CylindricShape::setRadius( double radius )
{
    radius_ = radius;
    doubleRadius_ = 2 * radius_;
    squaredRadius_ = pow( radius_, 2 );
}

double CylindricShape::getRadius() const
{
    return radius_;
}

void CylindricShape::setHeight( double height )
{
    height_ = height;
}

double CylindricShape::getHeight() const
{
    return height_;
}

double CylindricShape::getDoubleRadius() const
{
    return doubleRadius_;
}

double CylindricShape::getSquaredRadius() const
{
    return squaredRadius_;
}

} // namespace phycoub