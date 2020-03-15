/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:05:35
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 13:40:42
 */

#pragma once

#include "Vector.h"
#include "Particle.h"
#include "UseLog.h"

namespace phycoub
{

/*
 * Базовый класс для методов реализации граничных условий.
 * Для создания новых граничных условий необходимо унаследоваться от
 * данного класса и переопределить функцию psyMove.
 *
 * Базовая реализация содержит безконечные граничные условия.
 */
class BorderCondition : public UseLog
{
  public:
    virtual ~BorderCondition() = default;

    virtual void psyMove( const Vector& move, const Vector& speed, ParticlePtr particle );

  protected:
    void moveParticle( const Vector& coordinate, const Vector& speed,
        bool isBorderReached, ParticlePtr particle );
};

using BorderConditionPtr = std::shared_ptr< BorderCondition >;

} /* namespace phycoub */
