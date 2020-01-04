/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-05 00:19:52
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-05 00:22:16
 */

#pragma once

#include <memory>

namespace phycoub
{

class LifeTimeControllerIface
{
  public:
    virtual ~LifeTimeControllerIface() = default;

    virtual void phyControlLifeTime() = 0;
};

using LifeTimeControllerPtr = std::shared_ptr< LifeTimeControllerIface >;

} // namespace phycoub