/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:12:31
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 22:43:00
 */

#include <ElasticCoubCondition.h>
#include "Particle.h"

namespace phycoub
{

ElasticCoubCondition::ElasticCoubCondition( Vector* borders )
    : BorderCondition( borders )
{
}

void ElasticCoubCondition::psyMove( const Vector& move, ParticlePtr* particle )
{
    ( *particle )->coordinate_ += move;

    for ( int i = 0; i < 3; ++i )
    {
        if ( ( *particle )->coordinate_[ i ] < 0 )
        {
            ( *particle )->coordinate_[ i ] = -( *particle )->coordinate_[ i ];
            ( *particle )->speed_[ i ] = -( *particle )->speed_[ i ];
        }
        else if ( ( *particle )->coordinate_[ i ] > ( *borders_ )[ i ] )
        {
            ( *particle )->coordinate_[ i ]
                = 2 * ( *borders_ )[ i ] - ( *particle )->coordinate_[ i ];
            ( *particle )->speed_[ i ] = -( *particle )->speed_[ i ];
        }
    }
    ( *particle )->moved();
}

} // namespace phycoub
