/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-24 20:28:25
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-24 20:46:58
 */

#pragma once

#include "Vector.h"
#include "Particle.h"

namespace phycoub
{
/*
 * Абстрактный класс для реализации функции поля. Чтобы создать свою функцию поля
 * необходимо унаследоваться отданного класса и определить метод psyField.
 */
class FieldFunction
{
  public:
    virtual ~FieldFunction() = default;

    virtual Vector psyField(
        const Vector& mark, const Particle* particle = nullptr ) const = 0;
};

} // namespace phycoub
