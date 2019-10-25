/*
 * CyclicBorder.cpp
 *
 *  Created on: 20 дек. 2016 г.
 *      Author: serv
 */

#include <CyclicBorder.h>
#include "Particle.h"

namespace phycoub
{

CyclicBorder::CyclicBorder( Vector* borders )
    : BorderCondition( borders )
{
}

void CyclicBorder::psyMove( const Vector& move, ParticlePtr* particle )
{
    ( *particle )->coordinate_ += move;

    for ( int i = 0; i < 3; ++i )
    {
        if ( ( *particle )->coordinate_[ i ] < 0 )
        {
            ( *particle )->coordinate_[ i ] += ( *borders_ )[ i ];
        }
        else if ( ( *particle )->coordinate_[ i ] > ( *borders_ )[ i ] )
        {
            ( *particle )->coordinate_[ i ] -= ( *borders_ )[ i ];
        }
    }
    ( *particle )->moved();
}

} /* namespace phycoub */
