/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-06 21:20:28
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-14 14:42:05
 */

#include "QuantityLifeTimeController.h"

namespace phycoub
{

QuantityLifeTimeController::QuantityLifeTimeController( long lifeParticleCount,
    ParticleGroupPtr particleGroup, ParticleSourcePtr particleSource )
    : lifeParticleCount_( lifeParticleCount )
    , particleSource_( particleSource )
    , particleGroupReachedBorder_( std::make_shared< ParticleGroup >() )
{
    addParticleGroup( particleGroup );
}

// virtual override
void QuantityLifeTimeController::phyControlLifeTime()
{
    ParticleGroupPtr particleGroup = getParticleGroup();
    for ( const auto& particleReachedBorder : *particleGroupReachedBorder_ )
    {
        particleGroup->remove( particleReachedBorder->getId() );
    }
    particleGroupReachedBorder_->clear();

    const long givreBirthParticleCount = lifeParticleCount_ - particleGroup->size();
    for ( long i = 0; i < givreBirthParticleCount; ++i )
    {
        ParticlePtr particle = particleSource_->phyGiveBirthParticle();
        particleGroup->push_back( particle );
    }
}

// virtual override
void QuantityLifeTimeController::onBorderReached( ParticlePtr particle )
{
    particleGroupReachedBorder_->push_back( particle );
}

long QuantityLifeTimeController::getLifeParticleCount() const
{
    return lifeParticleCount_;
}

void QuantityLifeTimeController::setLifeParticleCount( long count )
{
    lifeParticleCount_ = count;
}

} // namespace phycoub