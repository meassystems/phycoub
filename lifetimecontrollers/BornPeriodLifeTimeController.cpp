/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-16 02:29:46
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-28 21:57:53
 */

#include "BornPeriodLifeTimeController.h"

namespace phycoub
{

BornPeriodLifeTimeController::BornPeriodLifeTimeController(
    double bornPeriod, ParticleSourcePtr particleSource )
    : LifeTimeControllerBase( particleSource )
    , bornPeriod_( bornPeriod )
{
}

// virtual override
void BornPeriodLifeTimeController::phyControlLifeTime( double dt /* = 0. */ )
{
    removeReachedBorderParticles();

    currentPeriod += dt;
    if ( currentPeriod >= bornPeriod_ && bornPeriod_ != 0 )
    {
        ParticleGroupPtr particleGroup = getParticleGroup();
        ParticleSourcePtr particleSource = getParticleSource();

        ParticlePtr particle = particleSource->phyGiveBirthParticle();
        particleGroup->push_back( particle );

        currentPeriod = 0.;
    }
}

void BornPeriodLifeTimeController::setBornPeriod( double bornPeriod )
{
    bornPeriod_ = bornPeriod;
}

double BornPeriodLifeTimeController::getBornPeriod() const
{
    return bornPeriod_;
}

// virtual override
ParticleGroupPtr BornPeriodLifeTimeController::getControlledParticleGroup()
{
    return getParticleGroup();
}

} // namespace phycoub