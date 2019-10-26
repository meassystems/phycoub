/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-26 08:38:39
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 09:01:06
 */

#include <ThermostatBorder.h>

namespace phycoub
{

ThermostatBorder::ThermostatBorder( const Vector& borders, double kB, double temp )
    : BorderCondition( borders )
    , kB_( kB )
    , temperature_( temp )
{
}

// virtual override
void ThermostatBorder::psyMove( const Vector& move, ParticlePtr* particle )
{
    ( *particle )->coordinate_ += move;

    bool fl = false;
    const Vector& borders = getBorders();

    for ( int i = 0; i < 3; ++i )
    {
        if ( i == 0 )
        {
            fl = false;
        }
        if ( ( *particle )->coordinate_[ i ] < 0 )
        {
            fl = true;
            ( *particle )->coordinate_[ i ] = -( *particle )->coordinate_[ i ];
            ( *particle )->speed_[ i ] = -( *particle )->speed_[ i ];
        }
        else if ( ( *particle )->coordinate_[ i ] > borders[ i ] )
        {
            fl = true;
            ( *particle )->coordinate_[ i ]
                = 2 * borders[ i ] - ( *particle )->coordinate_[ i ];
            ( *particle )->speed_[ i ] = -( *particle )->speed_[ i ];
        }
    }
    if ( fl )
    {
        temperatureControl( temperature_, kB_, particle );
    }
    ( *particle )->moved();
}

void ThermostatBorder::setKb( double kB )
{
    kB_ = kB;
}

double ThermostatBorder::getKb() const
{
    return kB_;
}

void ThermostatBorder::setTemperature( double temperature )
{
    temperature_ = temperature;
}

double ThermostatBorder::getTemperature() const
{
    return temperature_;
}

// static
void ThermostatBorder::temperatureControl( double temp, double kB, ParticlePtr* particle )
{
    double speedT = sqrt( ( 3 * kB * temp ) / ( *particle )->m_ );
    ( *particle )->speed_ *= ( speedT / ( *particle )->speed_.getModule() );
}

} // namespace phycoub
