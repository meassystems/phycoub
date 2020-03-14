/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-14 14:23:36
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-14 14:38:11
 */

#include "ContainOneParticleGroup.h"

namespace phycoub
{

ParticleGroupPtr ContainOneParticleGroup::getParticleGroup()
{
    return particleGroupList_.front();
}

// virtual override
void ContainOneParticleGroup::addParticleGroup( ParticleGroupPtr particleGroup )
{
    particleGroupList_.clear();
    particleGroupList_.push_back( particleGroup );
}

// virtual override
void ContainOneParticleGroup::removeParticleGroup( IDType id )
{
    if ( getParticleGroup()->getId() == id )
    {
        particleGroupList_.clear();
    }
}

// virtual override
void ContainOneParticleGroup::removeParticleGroup( ParticleGroupPtr particleGroup )
{
    removeParticleGroup( particleGroup->getId() );
}

// virtual override
void ContainOneParticleGroup::removeParticle( IDType id )
{
    getParticleGroup()->remove( id );
}

// virtual override
void ContainOneParticleGroup::removeParticle( ParticlePtr particle )
{
    removeParticle( particle->getId() );
}

// virtual override
ParticleGroupList ContainOneParticleGroup::getParticleGroupList()
{
    return particleGroupList_;
}

} // namespace phycoub