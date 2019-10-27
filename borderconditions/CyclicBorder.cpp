/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-26 08:23:20
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 08:26:47
 */

#include <CyclicBorder.h>
#include "Particle.h"

namespace phycoub
{

CyclicBorder::CyclicBorder( const Vector& borders )
    : BorderCondition( borders )
{
}

// virtual override
void CyclicBorder::psyMove(
    const Vector& move, const Vector& speed, ParticlePtr* particle )
{
    bool isBorderReached = false;
    const Vector& borders = getBorders();
    Vector coordinate = ( *particle )->getCoordinate() + move;

    for ( int i = 0; i < 3; ++i )
    {
        if ( coordinate[ i ] < 0 )
        {
            coordinate[ i ] += borders[ i ];
            isBorderReached = true;
        }
        else if ( coordinate[ i ] > borders[ i ] )
        {
            coordinate[ i ] -= borders[ i ];
            isBorderReached = true;
        }
    }

    moveParticle( coordinate, speed, isBorderReached, particle );
}

} // namespace phycoub
