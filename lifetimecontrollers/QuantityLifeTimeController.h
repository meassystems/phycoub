/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-06 20:23:47
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-06 21:32:27
 */

#pragma once

#include "LifeTimeControllerIface.h"
#include "BorderReachedObserver.h"
#include "ParticleSourceIface.h"
#include "ParticleGroup.h"

namespace phycoub
{

class QuantityLifeTimeController
    : public LifeTimeControllerIface
    , public BorderReachedObserver
{
  public:
    QuantityLifeTimeController( long lifeParticleCount, ParticleGroupPtr particleGroup,
        ParticleSourcePtr particleSource );
    virtual ~QuantityLifeTimeController() override = default;

    // Implementation of LifeTimeControllerIface
    virtual void phyControlLifeTime() override;

    // Implementation of BorderReachedObserver
    virtual void onBorderReached( ParticlePtr particle ) override;

  private:
    long lifeParticleCount_ = 0;
    ParticleGroupPtr particleGroup_;
    ParticleSourcePtr particleSource_;

    ParticleGroupPtr particleGroupReachedBorder_;
};

} // namespace phycoub