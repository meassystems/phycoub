/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-06 21:20:28
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-09 00:17:37
 */

#include "QuantityLifeTimeController.h"

namespace phycoub
{

QuantityLifeTimeController::QuantityLifeTimeController( long lifeParticleCount,
    ParticleGroupPtr particleGroup, ParticleSourcePtr particleSource )
    : lifeParticleCount_( lifeParticleCount )
    , particleGroup_( particleGroup )
    , particleSource_( particleSource )
    , particleGroupReachedBorder_( std::make_shared< ParticleGroup >() )
{
}

// virtual override
void QuantityLifeTimeController::phyControlLifeTime()
{
    for ( const auto& particleReachedBorder : *particleGroupReachedBorder_ )
    {
        particleGroup_->remove( particleReachedBorder->getId() );
    }
    particleGroupReachedBorder_->clear();

    const long givreBirthParticleCount = lifeParticleCount_ - particleGroup_->size();
    for ( long i = 0; i < givreBirthParticleCount; ++i )
    {
        ParticlePtr particle = particleSource_->phyGiveBirthParticle();
        particleGroup_->push_back( particle );
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