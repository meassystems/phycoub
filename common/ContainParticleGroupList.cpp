/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-11-05 23:22:22
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 13:30:22
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
    for ( ParticleGroupList::GroupIterator groupIterator = particleGroupList.beginGroup();
          groupIterator != particleGroupList.endGroup(); ++groupIterator )
    {
        if ( ( *groupIterator )->remove( id ) )
        {
            continue;
        }
    }
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