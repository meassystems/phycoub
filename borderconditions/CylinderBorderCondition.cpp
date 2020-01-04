/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-04 14:41:02
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-05 02:06:14
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
    const double squaredRadius = getSquaredRadius();
    const double doubleRadius = getDoubleRadius();
    const double height = getHeight();

    bool isBorderReached = false;
    Vector newCoordinate = ( *particle )->getCoordinate() + move;

    if ( pow( newCoordinate.x_, 2 ) + pow( newCoordinate.y_, 2 ) >= squaredRadius )
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