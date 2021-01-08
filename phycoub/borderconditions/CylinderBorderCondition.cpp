/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-04 14:41:02
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 13:42:02
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
    const Vector& move, const Vector& speed, ParticlePtr particle )
{
    const double radius = getRadius();
    const double squaredRadius = getSquaredRadius();
    const double doubleRadius = getDoubleRadius();
    const double height = getHeight();

    bool isBorderReached = false;
    Vector newCoordinate = particle->getCoordinate() + move;
    const Vector newCoordinateWithCylindricCenter{ newCoordinate.x() - radius,
        newCoordinate.y() - radius, newCoordinate.z() };

    if ( pow( newCoordinateWithCylindricCenter.x(), 2 )
            + pow( newCoordinateWithCylindricCenter.y(), 2 )
        >= squaredRadius )
    {
        isBorderReached = true;
        newCoordinate.x() -= doubleRadius;
        newCoordinate.y() -= doubleRadius;
    }

    if ( newCoordinate.z() < 0 )
    {
        isBorderReached = true;
        newCoordinate.z() += height;
    }
    else if ( newCoordinate.z() >= height )
    {
        isBorderReached = true;
        newCoordinate.z() -= height;
    }

    if ( isBorderReached )
    {
        borderReached( particle );
    }

    moveParticle( newCoordinate, speed, isBorderReached, particle );
}

} // namespace phycoub