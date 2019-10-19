/*
 * ThermostatBorder.cpp
 *
 *  Created on: Dec 26, 2016
 *      Author: root
 */

#include <ThermostatBorder.h>

#include "temperatureControl.h"

namespace phycoub
{

ThermostatBorder::ThermostatBorder( Vector *borders, double *kB, double *temp )
    : BorderCondition( borders )
    , kB_( kB )
    , temperature_( temp )
{
}
ThermostatBorder::~ThermostatBorder()
{
}

void ThermostatBorder::psyMove( const Vector &move, Particle &particle )
{
    particle.coordinate_ += move;

    bool fl = false;
    for ( int i = 0; i < 3; ++i )
    {
        if ( i == 0 )
        {
            fl = false;
        }
        if ( particle.coordinate_[ i ] < 0 )
        {
            fl = true;
            particle.coordinate_[ i ] = -particle.coordinate_[ i ];
            particle.speed_[ i ] = -particle.speed_[ i ];
        }
        else if ( particle.coordinate_[ i ] > ( *borders_ )[ i ] )
        {
            fl = true;
            particle.coordinate_[ i ]
                = 2 * ( *borders_ )[ i ] - particle.coordinate_[ i ];
            particle.speed_[ i ] = -particle.speed_[ i ];
        }
    }
    if ( fl )
    {
        temperatureControl( *temperature_, *kB_, particle );
    }
}

} /* namespace phycoub */
