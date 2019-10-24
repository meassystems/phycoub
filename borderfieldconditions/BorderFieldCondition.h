/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-24 19:46:31
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-24 20:46:28
 */

#pragma once

#include "Vector.h"
#include "Particle.h"
#include "FieldFunction.h"

namespace phycoub
{

class CreateField;
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
        FieldFunction* fieldFunction, const Particle& particle, const Vector& mark );
};

} // namespace phycoub
