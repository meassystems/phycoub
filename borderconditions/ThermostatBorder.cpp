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
void ThermostatBorder::psyMove(
    const Vector& move, const Vector& newSpeed, ParticlePtr* particle )
{
    const Vector& borders = getBorders();
    Vector coordinate = ( *particle )->getCoordinate();
    Vector speed = newSpeed;

    bool isBorderReached = false;
    coordinate += move;

    for ( int i = 0; i < 3; ++i )
    {
        if ( coordinate[ i ] < 0 )
        {
            isBorderReached = true;
            coordinate[ i ] *= -1;
            speed[ i ] *= -1;
        }
        else if ( coordinate[ i ] > borders[ i ] )
        {
            isBorderReached = true;
            coordinate[ i ] = 2 * borders[ i ] - coordinate[ i ];
            speed[ i ] *= -1;
        }
    }
    if ( isBorderReached )
    {
        temperatureControl( temperature_, kB_, ( *particle )->m_, &speed );
    }

    ( *particle )->move( coordinate, speed );
    // todo: twice becose if once - invalid result for calculation models uses previes
    // values
    if ( isBorderReached )
    {
        ( *particle )->move( coordinate, speed );
    }
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
void ThermostatBorder::temperatureControl(
    double temp, double kB, double m, Vector* speed )
{
    double speedT = sqrt( ( 3 * kB * temp ) / m );
    *speed *= ( speedT / speed->getModule() );
}

} // namespace phycoub
