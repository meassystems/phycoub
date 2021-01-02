/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-16 01:48:46
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-16 02:32:53
 */

#include "RemoveParticleIfBorderReachedBase.h"

namespace phycoub
{

RemoveParticleIfBorderReachedBase::RemoveParticleIfBorderReachedBase()
    : particleGroupReachedBorder_( std::make_shared< ParticleGroup >() )
{
}

// virtual override
void RemoveParticleIfBorderReachedBase::onBorderReached( ParticlePtr particle )
{
    particleGroupReachedBorder_->push_back( particle );
}

void RemoveParticleIfBorderReachedBase::removeReachedBorderParticles()
{
    ParticleGroupPtr particleGroup = getControlledParticleGroup();
    for ( const auto& particleReachedBorder : *particleGroupReachedBorder_ )
    {
        particleGroup->remove( particleReachedBorder->getId() );
    }
    particleGroupReachedBorder_->clear();
}

} // namespace phycoub