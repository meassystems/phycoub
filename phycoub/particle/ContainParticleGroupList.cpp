/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-11-05 23:22:22
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 16:57:51
 */

#include "ContainParticleGroupList.h"

namespace phycoub
{

// virtual override
void ContainParticleGroupList::addParticleGroup( ParticleGroupPtr particleGroup )
{
    particleGroupList.push_back( particleGroup );
}

// virtual override
void ContainParticleGroupList::removeParticleGroup( IDType id )
{
    particleGroupList.removeGroup( id );
}

// virtual override
void ContainParticleGroupList::removeParticleGroup( ParticleGroupPtr particleGroup )
{
    removeParticleGroup( particleGroup->getId() );
}

// virtual override
void ContainParticleGroupList::removeParticle( IDType id )
{
    particleGroupList.removeParticle( id );
}

// virtual override
void ContainParticleGroupList::removeParticle( ParticlePtr particle )
{
    removeParticle( particle->getId() );
}

// virtual override
ParticleGroupList ContainParticleGroupList::getParticleGroupList()
{
    return particleGroupList;
}

} // namespace phycoub