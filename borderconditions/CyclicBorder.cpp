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
void CyclicBorder::psyMove( const Vector& move, ParticlePtr* particle )
{
    ( *particle )->coordinate_ += move;

    const Vector& borders = getBorders();
    for ( int i = 0; i < 3; ++i )
    {
        if ( ( *particle )->coordinate_[ i ] < 0 )
        {
            ( *particle )->coordinate_[ i ] += borders[ i ];
        }
        else if ( ( *particle )->coordinate_[ i ] > borders[ i ] )
        {
            ( *particle )->coordinate_[ i ] -= borders[ i ];
        }
    }
    ( *particle )->moved();
}

} // namespace phycoub
