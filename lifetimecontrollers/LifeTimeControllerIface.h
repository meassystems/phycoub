/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-05 00:19:52
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-06 01:19:23
 */

#pragma once

#include <memory>
#include <list>

#include "HasId.h"

namespace phycoub
{

class LifeTimeControllerIface : public HasId
{
  public:
    virtual ~LifeTimeControllerIface() = default;

    virtual void phyControlLifeTime() = 0;
};

using LifeTimeControllerPtr = std::shared_ptr< LifeTimeControllerIface >;
using LifeTimeControllerList = std::list< LifeTimeControllerPtr >;

} // namespace phycoub