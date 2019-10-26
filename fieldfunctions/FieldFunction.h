/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-24 20:28:25
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 09:04:15
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
        const Vector& mark, const ParticlePtr particle = nullptr ) const = 0;
};

using FieldFunctionPtr = std::shared_ptr< FieldFunction >;

} // namespace phycoub
