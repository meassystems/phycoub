/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-24 19:46:31
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 19:08:30
 */

#pragma once

#include <memory>

#include "Vector.h"
#include "Particle.h"
#include "FieldIface.h"

namespace phycoub
{

class DynamicFieldCreator;
/*
 * Базовый класс для задания граничных условий поля взаимодействия.
 * Чтобы создать свой метод необходим унаследоваться от данного класса и
 * переопределить метод phyFieldWithBorderCondition.
 *
 * Базовая реализация содержит бесконечные граничные условия.
 */
class BorderFieldCondition
{
  public:
    BorderFieldCondition() = default;
    virtual ~BorderFieldCondition() = default;

    virtual Vector phyFieldWithBorderCondition(
        FieldPtr field, const ParticlePtr particle, const Vector& mark );
};

using BorderFieldConditionPtr = std::shared_ptr< BorderFieldCondition >;

} // namespace phycoub
