/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 16:32:05
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 18:13:52
 */

#include "ParticleGroup.h"

namespace phycoub
{

typename ParticleGroup::ContainerType::iterator ParticleGroup::begin()
{
    return particles_.begin();
}

typename ParticleGroup::ContainerType::iterator ParticleGroup::end()
{
    return particles_.end();
}

void ParticleGroup::push_back( ParticlePtr particle )
{
    particles_.push_back( particle );
}

size_t ParticleGroup::size() const
{
    return particles_.size();
}

void ParticleGroup::clear()
{
    particles_.clear();
}

bool ParticleGroup::operator==( const ParticleGroup& particleGroup )
{
    return getId() == particleGroup.getId();
}

bool ParticleGroup::remove( IDType id )
{
    for ( auto particleIterator = begin(); particleIterator != end(); ++particleIterator )
    {
        if ( ( *particleIterator )->getId() == id )
        {
            particles_.erase( particleIterator );
            return true;
        }
    }

    return false;
}

} // namespace phycoub