/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 16:20:27
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-14 14:35:28
 */

#pragma once

#include <list>

#include "ParticleGroup.h"

namespace phycoub
{

class ParticleGroupList final
{
  public:
    ParticleGroupList() = default;
    ~ParticleGroupList() = default;

    using ContainerType = std::list< ParticleGroupPtr >;

    typename ContainerType::iterator begin();
    typename ContainerType::iterator end();
    typename ContainerType::const_iterator cbegin() const;
    typename ContainerType::const_iterator cend() const;
    void push_back( ParticleGroupPtr group );
    ParticleGroupPtr front();
    void clear();
    size_t size() const;
    bool empty() const;

    ParticleGroupList deepCopy() const;

    void removeParticle( IDType id );
    bool removeGroup( IDType id );

    size_t getParticleCount() const;

    template< typename FunctionType >
    void forEachGroup( FunctionType function ) const;
    template< typename FunctionType >
    void forEachParticle( FunctionType function ) const;

  private:
    ContainerType particleGroups_;
};

template< typename FunctionType >
void ParticleGroupList::forEachGroup( FunctionType function ) const
{
    for ( auto group : particleGroups_ )
    {
        function( group );
    }
}

template< typename FunctionType >
void ParticleGroupList::forEachParticle( FunctionType function ) const
{
    for ( auto group : particleGroups_ )
    {
        for ( auto particle : *group )
        {
            function( particle );
        }
    }
}

} // namespace phycoub