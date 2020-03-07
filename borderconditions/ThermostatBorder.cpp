/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-26 08:38:39
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-10 20:38:32
 */

#include <ThermostatBorder.h>

#include <math.h>

namespace phycoub
{

ThermostatBorder::ThermostatBorder( const Vector& borders, double kB, double temp )
    : CubicShape( borders )
    , kB_( kB )
    , temperature_( temp )
{
}

// virtual override
void ThermostatBorder::psyMove(
    const Vector& move, const Vector& speed, ParticlePtr* particle )
{
    const Vector& borders = getBorders();
    Vector coordinate = ( *particle )->getCoordinate();
    Vector newSpeed = speed;

    bool isBorderReached = false;
    coordinate += move;

    for ( int i = 0; i < 3; ++i )
    {
        if ( coordinate[ i ] < 0 )
        {
            isBorderReached = true;
            coordinate[ i ] *= -1;
            newSpeed[ i ] *= -1;
        }
        else if ( coordinate[ i ] > borders[ i ] )
        {
            isBorderReached = true;
            coordinate[ i ] = 2 * borders[ i ] - coordinate[ i ];
            newSpeed[ i ] *= -1;
        }
    }
    if ( isBorderReached )
    {
        temperatureControl(
            temperature_, kB_, ( *particle )->getOptions().m_, &newSpeed );
    }

    moveParticle( coordinate, newSpeed, isBorderReached, particle );
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
