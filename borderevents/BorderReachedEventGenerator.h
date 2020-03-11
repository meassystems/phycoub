/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-03 14:10:02
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-12 00:31:30
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
    void addBorderReachedObserver( BorderReachedObserverPtr observer );

  private:
    std::list< std::weak_ptr< BorderReachedObserver > > observers;
};

} // namespace phycoub