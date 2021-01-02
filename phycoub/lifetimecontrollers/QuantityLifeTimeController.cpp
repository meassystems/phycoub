/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-06 21:20:28
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-16 02:34:39
 */

#include "QuantityLifeTimeController.h"

namespace phycoub
{

QuantityLifeTimeController::QuantityLifeTimeController(
    long lifeParticleCount, ParticleSourcePtr particleSource )
    : LifeTimeControllerBase( particleSource )
    , lifeParticleCount_( lifeParticleCount )
{
}

long QuantityLifeTimeController::getLifeParticleCount() const
{
    return lifeParticleCount_;
}

void QuantityLifeTimeController::setLifeParticleCount( long count )
{
    lifeParticleCount_ = count;
}

// virtual override
void QuantityLifeTimeController::phyControlLifeTime( double dt /* = 0. */ )
{
    removeReachedBorderParticles();

    ParticleGroupPtr particleGroup = getParticleGroup();
    ParticleSourcePtr particleSource = getParticleSource();
    const long givreBirthParticleCount = lifeParticleCount_ - particleGroup->size();

    for ( long i = 0; i < givreBirthParticleCount; ++i )
    {
        ParticlePtr particle = particleSource->phyGiveBirthParticle();
        particleGroup->push_back( particle );
    }
}

// virtual override
ParticleGroupPtr QuantityLifeTimeController::getControlledParticleGroup()
{
    return getParticleGroup();
}

} // namespace phycoub