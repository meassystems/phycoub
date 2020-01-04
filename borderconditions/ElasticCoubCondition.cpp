/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:12:31
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-04 14:26:40
 */

#include <ElasticCoubCondition.h>
#include "Particle.h"

namespace phycoub
{

ElasticCoubCondition::ElasticCoubCondition( const Vector& borders )
    : CubicShape( borders )
{
}

// virtual override
void ElasticCoubCondition::psyMove(
    const Vector& move, const Vector& speed, ParticlePtr* particle )
{
    const Vector& borders = getBorders();
    Vector coordinate = ( *particle )->getCoordinate();
    Vector newSpeed = speed;

    bool isBorderReached = false;
    coordinate += move;

    for ( int i = 0; i < 3; ++i )
    {
        if ( coordinate[ i ] < 0 )
        {
            coordinate[ i ] *= -1;
            newSpeed[ i ] *= -1;
            isBorderReached = true;
        }
        else if ( coordinate[ i ] > borders[ i ] )
        {
            coordinate[ i ] = 2 * borders[ i ] - coordinate[ i ];
            newSpeed[ i ] *= -1;
            isBorderReached = true;
        }
    }

    moveParticle( coordinate, newSpeed, isBorderReached, particle );
}

} // namespace phycoub
