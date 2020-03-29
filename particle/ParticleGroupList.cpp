/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 16:32:05
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-29 09:51:00
 */

#include "ParticleGroupList.h"

namespace phycoub
{

typename ParticleGroupList::ContainerType::iterator ParticleGroupList::begin()
{
    return particleGroups_.begin();
}

typename ParticleGroupList::ContainerType::iterator ParticleGroupList::end()
{
    return particleGroups_.end();
}

typename ParticleGroupList::ContainerType::const_iterator
ParticleGroupList::cbegin() const
{
    return particleGroups_.cbegin();
}

typename ParticleGroupList::ContainerType::const_iterator ParticleGroupList::cend() const
{
    return particleGroups_.cend();
}

void ParticleGroupList::push_back( ParticleGroupPtr group )
{
    particleGroups_.push_back( group );
}

ParticleGroupPtr ParticleGroupList::front()
{
    return particleGroups_.front();
}

void ParticleGroupList::clear()
{
    particleGroups_.clear();
}

size_t ParticleGroupList::size() const
{
    return particleGroups_.size();
}

bool ParticleGroupList::empty() const
{
    return particleGroups_.empty();
}

ParticleGroupList ParticleGroupList::deepCopy() const
{
    ParticleGroupList copy;
    for ( auto group : particleGroups_ )
    {
        ParticleGroupPtr newGroup = std::make_shared< ParticleGroup >();
        for ( auto particle : *group )
        {
            ParticlePtr newParticle = std::make_shared< Particle >( *particle );
            newGroup->push_back( newParticle );
        }
        copy.push_back( newGroup );
    }

    return copy;
}

void ParticleGroupList::removeParticle( IDType id )
{
    forEachGroup( [id]( ParticleGroupPtr group ) { group->remove( id ); } );
}

bool ParticleGroupList::removeGroup( IDType id )
{
    for ( auto groupIterator = begin(); groupIterator != end(); ++groupIterator )
    {
        if ( ( *groupIterator )->getId() == id )
        {
            particleGroups_.erase( groupIterator );
            return true;
        }
    }

    return false;
}

size_t ParticleGroupList::getParticleCount() const
{
    size_t particleCount = 0;
    forEachParticle( [&particleCount]( ParticlePtr particle ) { ++particleCount; } );
    return particleCount;
}

} // namespace phycoub