/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-05 01:33:26
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-05 01:39:01
 */

#pragma once

#include <memory>

namespace phycoub
{

class ParticleSourceIface
{

  public:
    virtual ~ParticleSourceIface() = default;

    virtual void phyGiveBirthParticle() = 0;
};

using ParticleSourcePtr = std::shared_ptr< ParticleSourceIface >;

} // namespace phycoub