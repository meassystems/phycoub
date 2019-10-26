/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:05:35
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 08:23:53
 */

#pragma once

#include "Vector.h"
#include "Particle.h"

namespace phycoub
{

/*
 * Базовый класс для методов реализации граничных условий.
 * Для создания новых граничных условий необходимо унаследоваться от
 * данного класса и переопределить функцию psyMove.
 *
 * Базовая реализация содержит безконечные граничные условия.
 */
class BorderCondition
{
  public:
    BorderCondition( const Vector& borders );
    virtual ~BorderCondition() = default;

    virtual void psyMove( const Vector& move, ParticlePtr* particle );

    void setBorders( const Vector& borders );
    const Vector& getBorders() const;

  private:
    Vector borders_;
};

using BorderConditionPtr = std::shared_ptr< BorderCondition >;

} /* namespace phycoub */
