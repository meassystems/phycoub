/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-03 14:10:02
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-14 09:21:55
 */

#pragma once

#include <list>
#include <memory>

#include "Particle.h"
#include "BorderReachedObserver.h"

namespace phycoub
{
/*
 * Базовый класс для граничных условий, которые кидаю событие о достижение границ
 * частицами
 */
class BorderReachedEventGenerator
{
  public:
    virtual ~BorderReachedEventGenerator() = default;

    virtual void borderReached( ParticlePtr particle );
    void addBorderReachedObserver( BorderReachedObserverWeakPtr observer );

  private:
    std::list< BorderReachedObserverWeakPtr > observers;
};

} // namespace phycoub