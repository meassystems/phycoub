/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:12:31
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 09:00:45
 */

#include <ElasticCoubCondition.h>
#include "Particle.h"

namespace phycoub
{

ElasticCoubCondition::ElasticCoubCondition( const Vector& borders )
    : BorderCondition( borders )
{
}

// virtual override
void ElasticCoubCondition::psyMove(
    const Vector& move, const Vector& newSpeed, ParticlePtr* particle )
{
    const Vector& borders = getBorders();
    Vector coordinate = ( *particle )->getCoordinate();
    Vector speed = ( *particle )->getSpeed();

    bool isBorderReached = false;
    coordinate += move;

    for ( int i = 0; i < 3; ++i )
    {
        if ( coordinate[ i ] < 0 )
        {
            coordinate[ i ] *= -1;
            speed[ i ] *= -1;
            isBorderReached = true;
        }
        else if ( coordinate > borders[ i ] )
        {
            coordinate[ i ] = 2 * borders[ i ] - coordinate[ i ];
            speed[ i ] *= -1;
            isBorderReached = true;
        }
    }

    ( *particle )->move( coordinate, speed );
    // todo: twice becose if once - invalid result for calculation models uses previes
    // values
    if ( isBorderReached )
    {
        ( *particle )->move( coordinate, speed );
    }
}

} // namespace phycoub
