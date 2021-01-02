/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-05 00:19:52
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-16 01:35:07
 */

#pragma once

#include <memory>
#include <list>

#include "HasId.h"

namespace phycoub
{
/*
 * Интерфейс для сущностей, которые управляют временем жизни частиц
 */
class LifeTimeControllerIface : public HasId
{
  public:
    virtual ~LifeTimeControllerIface() = default;

    virtual void phyControlLifeTime( double dt = 0. ) = 0;
};

using LifeTimeControllerPtr = std::shared_ptr< LifeTimeControllerIface >;
using LifeTimeControllerList = std::list< LifeTimeControllerPtr >;

} // namespace phycoub