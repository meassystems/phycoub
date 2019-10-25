/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:39:46
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 18:47:07
 */

#include "measurement.h"

#include <algorithm>
#include <math.h>

namespace phycoub
{

double getTemperature( double kB, ParticleGroupPtr particles )
{
    const double result_ = getWk( particles ) * 2. / 3. / kB;
    return result_;
}

double getTemperatureWithoutEnergyTranslationalMotionSystem(
    double kB, ParticleGroupPtr particles )
{
    const double result_ = getWkWithoutTranslationalMotion( particles ) * 2. / 3. / kB;
    return result_;
}

double getWk( ParticleGroupPtr particles )
{
    double speedQ = .0;
    for ( ParticlePtr particle : *particles )
    {
        speedQ += pow( particle->speed_.getModule(), 2 );
    }

    const double result_ = ( *particles )[ 0 ]->m_ * speedQ / particles->size() / 2;
    return result_;
}

double getWkWithoutTranslationalMotion( ParticleGroupPtr particles )
{
    double speedQ = .0;
    Vector speedSystem( 0 );

    for ( ParticlePtr particle : *particles )
    {
        speedSystem += particle->speed_;
    }
    speedSystem /= particles->size();

    speedQ = 0;
    for ( ParticlePtr particle : *particles )
    {
        speedQ += pow( ( particle->speed_ - speedSystem ).getModule(), 2 );
    }
    double result_ = ( *particles )[ 0 ]->m_ * speedQ / particles->size() / 2;

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
