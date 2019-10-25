/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:05:35
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 22:32:04
 */

#pragma once

#include "Vector.h"
#include "ParticleGroup.h"

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
    BorderCondition( Vector* borders );
    virtual ~BorderCondition() = default;

    virtual void psyMove( const Vector& move, ParticlePtr* particle );

    Vector* borders_;
};

using BorderConditionPtr = std::shared_ptr< BorderCondition >;

} /* namespace phycoub */
