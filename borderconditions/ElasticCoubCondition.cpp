/*
 * ElasticCoubCondition.cpp
 *
 *  Created on: 19 ���. 2016 �.
 *      Author: SFrancishkov
 */

#include <ElasticCoubCondition.h>
#include "Particle.h"

namespace phycoub
{

ElasticCoubCondition::ElasticCoubCondition( Vector *borders )
    : BorderCondition( borders )
{
}
ElasticCoubCondition::~ElasticCoubCondition()
{
}

void ElasticCoubCondition::psyMove( const Vector &move, Particle &particle )
{
    particle.coordinate_ += move;

    for ( int i = 0; i < 3; ++i )
    {
        if ( particle.coordinate_[ i ] < 0 )
        {
            particle.coordinate_[ i ] = -particle.coordinate_[ i ];
            particle.speed_[ i ] = -particle.speed_[ i ];
        }
        else if ( particle.coordinate_[ i ] > ( *borders_ )[ i ] )
        {
            particle.coordinate_[ i ]
                = 2 * ( *borders_ )[ i ] - particle.coordinate_[ i ];
            particle.speed_[ i ] = -particle.speed_[ i ];
        }
    }
}

} /* namespace phycoub */
