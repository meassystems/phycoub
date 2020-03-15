/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-16 02:02:47
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-16 02:21:05
 */

#pragma once

#include "LifeTimeControllerIface.h"
#include "ContainOneParticleGroup.h"
#include "ParticleSourceIface.h"

namespace phycoub
{

class LifeTimeControllerBase
    : public LifeTimeControllerIface
    , public ContainOneParticleGroup
{
  public:
    LifeTimeControllerBase( ParticleSourcePtr particleSource );
    virtual ~LifeTimeControllerBase() override = default;

    void setParticleGroup( ParticleGroupPtr particleGroup );

    void setParticleSource( ParticleSourcePtr particlesource );
    ParticleSourcePtr getParticleSource() const;

  private:
    ParticleSourcePtr particleSource_;
};

} // namespace phycoub