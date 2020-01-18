/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-11-11 23:20:40
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-09 19:01:35
 */

#include "RadialHomogeneousField.h"

#include "VectorUtils.h"

namespace phycoub
{

RadialHomogeneousField::RadialHomogeneousField( const Vector& center, double radius )
    : center_( center )
    , radius_( radius )
{
}

// virtual override
Vector RadialHomogeneousField::getDirection( const Vector& mark ) const
{
    Vector result = mark - center_;
    return VectorUtils::normalizeVector( std::move( result ) );
}

void RadialHomogeneousField::setCenter( const Vector& center )
{
    center_ = center;
}

const Vector& RadialHomogeneousField::getCenter() const
{
    return center_;
}

double RadialHomogeneousField::getRadius() const
{
    return radius_;
}

void RadialHomogeneousField::setRadius( double radius )
{
    radius_ = radius;
}

} // namespace phycoub