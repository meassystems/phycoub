/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-11-12 23:02:17
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-12 00:35:49
 */

#pragma once

#include <memory>

#include "FieldIface.h"
#include "Vector.h"

namespace phycoub
{
/*
 * Интерфейс для гомогенных полей
 */
class HomogeneousFieldIface : public FieldIface
{
  public:
    HomogeneousFieldIface() = default;
    virtual ~HomogeneousFieldIface() = default;

    virtual Vector getDirection( const Vector& mark ) const = 0;
};

using HomogeneousFieldPtr = std::shared_ptr< HomogeneousFieldIface >;

} // namespace phycoub