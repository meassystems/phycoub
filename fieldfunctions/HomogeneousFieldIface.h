/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-11-12 23:02:17
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-12 23:21:57
 */

#pragma once

#include <memory>

#include "FieldIface.h"
#include "Vector.h"

namespace phycoub
{

class HomogeneousFieldIface : public FieldIface
{
  public:
    HomogeneousFieldIface() = default;
    virtual ~HomogeneousFieldIface() = default;

    virtual Vector getDirection( const Vector& mark = Vector{} ) const = 0;
};

using HomogeneousFieldPtr = std::shared_ptr< HomogeneousFieldIface >;

} // namespace phycoub