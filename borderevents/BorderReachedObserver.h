/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-03 14:16:29
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-03 14:32:08
 */

#pragma once

#include <memory>

#include "Particle.h"

namespace phycoub
{

class BorderReachedObserver
{
  public:
    virtual ~BorderReachedObserver() = default;

    virtual void onBorderReached( ParticlePtr particle ) = 0;
};

using BorderReachedObserverPtr = std::shared_ptr< BorderReachedObserver >;

} // namespace phycoub
