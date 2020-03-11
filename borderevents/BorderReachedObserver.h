/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-03 14:16:29
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-12 00:32:17
 */

#pragma once

#include <memory>

#include "Particle.h"

namespace phycoub
{
/*
 * Интрефейс для подписчиков на событие от граничных условий о достижении границ частицами
 */
class BorderReachedObserver
{
  public:
    virtual ~BorderReachedObserver() = default;

    virtual void onBorderReached( ParticlePtr particle ) = 0;
};

using BorderReachedObserverPtr = std::shared_ptr< BorderReachedObserver >;

} // namespace phycoub
