/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-11-05 23:22:22
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-05 23:52:30
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

ParticleGroupList* ContainParticleGroupList::getParticleGroupList()
{
    return &particleGroupList;
}

} // namespace phycoub