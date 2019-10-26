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
void ElasticCoubCondition::psyMove( const Vector& move, ParticlePtr* particle )
{
    ( *particle )->coordinate_ += move;

    const Vector& borders = getBorders();
    for ( int i = 0; i < 3; ++i )
    {
        if ( ( *particle )->coordinate_[ i ] < 0 )
        {
            ( *particle )->coordinate_[ i ] = -( *particle )->coordinate_[ i ];
            ( *particle )->speed_[ i ] = -( *particle )->speed_[ i ];
        }
        else if ( ( *particle )->coordinate_[ i ] > borders[ i ] )
        {
            ( *particle )->coordinate_[ i ]
                = 2 * borders[ i ] - ( *particle )->coordinate_[ i ];
            ( *particle )->speed_[ i ] = -( *particle )->speed_[ i ];
        }
    }
    ( *particle )->moved();
}

} // namespace phycoub
