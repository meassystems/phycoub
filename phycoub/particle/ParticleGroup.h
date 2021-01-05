/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 16:20:27
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 17:52:25
 */

#pragma once

#include <list>

#include "Particle.h"

namespace phycoub
{

class ParticleGroup final : public HasId
{
  public:
    ParticleGroup() = default;
    virtual ~ParticleGroup() = default;

    using ContainerType = std::list< ParticlePtr >;

    typename ContainerType::iterator begin();
    typename ContainerType::iterator end();
    void push_back( ParticlePtr particle );
    size_t size() const;
    void clear();

    bool operator==( const ParticleGroup& particleGroup );

    bool remove( IDType id );

  private:
    ContainerType particles_;
};

using ParticleGroupPtr = std::shared_ptr< ParticleGroup >;

} // namespace phycoub