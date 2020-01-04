/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-04 14:41:02
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-04 15:01:05
 */

#include "CylinderBorderCondition.h"

#include <math.h>

namespace phycoub
{

CylinderBorderCondition::CylinderBorderCondition( double radius, double height )
    : radius_( radius )
    , height_( height )
{
    doubleRadius_ = 2 * radius_;
    squaredRadius_ = pow( radius_, 2 );
}

// virtual override
void CylinderBorderCondition::psyMove(
    const Vector& move, const Vector& speed, ParticlePtr* particle )
{
    bool isBorderReached = false;

    Vector newCoordinate = ( *particle )->getCoordinate() + move;
    if ( pow( newCoordinate.x_, 2 ) + pow( newCoordinate.y_, 2 ) >= squaredRadius_ )
    {
        isBorderReached = true;
        newCoordinate.x_ -= doubleRadius_;
        newCoordinate.y_ -= doubleRadius_;
    }

    if ( newCoordinate.z_ < 0 )
    {
        isBorderReached = true;
        newCoordinate.z_ += height_;
    }
    else if ( newCoordinate.z_ >= height_ )
    {
        isBorderReached = true;
        newCoordinate.z_ -= height_;
    }

    if ( isBorderReached )
    {
        borderReached( *particle );
    }

    moveParticle( newCoordinate, speed, isBorderReached, particle );
}

void CylinderBorderCondition::setRadius( double radius )
{
    radius_ = radius;
    doubleRadius_ = 2 * radius_;
    squaredRadius_ = pow( radius_, 2 );
}

double CylinderBorderCondition::getRadius() const
{
    return radius_;
}

void CylinderBorderCondition::setHeight( double height )
{
    height_ = height;
}

double CylinderBorderCondition::getHeight() const
{
    return height_;
}

} // namespace phycoub