/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:19:09
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 00:56:07
 */

#include "temperatureControl.h"

namespace phycoub
{

void temperatureControl( double temp, double kB, ParticlePtr particle )
{
    double speedT = sqrt( ( 3 * kB * temp ) / particle->m_ );
    particle->speed_ *= ( speedT / particle->speed_.getModule() );
}

void temperatureControl( double temp, double kB, ParticleGroupPtr particleGroup )
{
    for ( ParticlePtr particle : *particleGroup )
    {
        temperatureControl( temp, kB, particle );
    }
}

void temperatureControl( double temp, double kB, ParticleGroupList particleGroupList )
{
    for ( ParticlePtr particle : particleGroupList )
    {
        temperatureControl( temp, kB, particle );
    }
}

} // namespace phycoub
