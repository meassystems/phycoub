/*
 * measurement.cpp
 *
 *  Created on: 22 ���. 2016 �.
 *      Author: SFrancishkov
 */

#include "measurement.h"

#include <algorithm>
#include <math.h>

namespace phycoub
{

double getTemperature(
    const double &kB, const int &num, std::vector< Particle * > *particles, ... )
{
    double result_ = getWk( num, particles ) * 2. / 3. / kB;

    return result_;
}

double getTemperatureWithoutEnergyTranslationalMotionSystem(
    const double &kB, const int &num, std::vector< Particle * > *particles, ... )
{
    double result_ = getWkWithoutTranslationalMotion( num, particles ) * 2. / 3. / kB;

    return result_;
}

double getWk( int num, std::vector< Particle * > *particles, ... )
{
    double result_ = 0., speedQ = .0;

    for ( int i = 0; i < num; ++i )
    {
        speedQ = 0;
        for ( Particle *particle : *particles )
        {
            speedQ += pow( particle->speed_.getModule(), 2 );
        }
        if ( i == 0 )
        {
            result_ = ( *particles )[ 0 ]->m_ * speedQ / particles->size() / 2;
        }
        else
        {
            result_ += ( *particles )[ 0 ]->m_ * speedQ / particles->size() / 2 / 2;
        }
        ++particles;
    }

    return result_;
}

double getWkWithoutTranslationalMotion(
    int num, std::vector< Particle * > *particles, ... )
{
    double result_ = 0., speedQ = .0;
    Vector speedSystem( 0 );

    for ( int i = 0; i < num; ++i )
    {
        speedSystem = 0;
        for ( Particle *particle : *particles )
        {
            speedSystem += particle->speed_;
        }
        speedSystem /= particles->size();

        speedQ = 0;
        for ( Particle *particle : *particles )
        {
            speedQ += pow( ( particle->speed_ - speedSystem ).getModule(), 2 );
        }
        if ( i == 0 )
        {
            result_ = ( *particles )[ 0 ]->m_ * speedQ / particles->size() / 2;
        }
        else
        {
            result_ += ( *particles )[ 0 ]->m_ * speedQ / particles->size() / 2 / 2;
        }
        ++particles;
    }

    return result_;
}
/*
double getWp(std::vector<Particle>& particles) {

        double result_ = 0.;

        for_each(particles.begin(), particles.end(), [&](Particle& particle) {
                //result_ += particle.interworking_;
        });

        return result_;
}
*/
} // namespace phycoub
