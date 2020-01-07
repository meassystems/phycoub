/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-04 14:41:02
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-08 01:58:25
 */

#include "CylinderBorderCondition.h"

#include <math.h>

namespace phycoub
{

CylinderBorderCondition::CylinderBorderCondition( double radius, double height )
    : CylindricShape( radius, height )
{
}

// virtual override
void CylinderBorderCondition::psyMove(
    const Vector& move, const Vector& speed, ParticlePtr* particle )
{
    const double radius = getRadius();
    const double squaredRadius = getSquaredRadius();
    const double doubleRadius = getDoubleRadius();
    const double height = getHeight();

    bool isBorderReached = false;
    Vector newCoordinate = ( *particle )->getCoordinate() + move;
    const Vector newCoordinateWithCylindricCenter{ newCoordinate.x_ - radius,
        newCoordinate.y_ - radius, newCoordinate.z_ };

    if ( pow( newCoordinateWithCylindricCenter.x_, 2 )
            + pow( newCoordinateWithCylindricCenter.y_, 2 )
        >= squaredRadius )
    {
        isBorderReached = true;
        newCoordinate.x_ -= doubleRadius;
        newCoordinate.y_ -= doubleRadius;
    }

    if ( newCoordinate.z_ < 0 )
    {
        isBorderReached = true;
        newCoordinate.z_ += height;
    }
    else if ( newCoordinate.z_ >= height )
    {
        isBorderReached = true;
        newCoordinate.z_ -= height;
    }

    if ( isBorderReached )
    {
        borderReached( *particle );
    }

    moveParticle( newCoordinate, speed, isBorderReached, particle );
}

} // namespace phycoub