/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-16 01:33:21
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-28 21:56:53
 */

#pragma once

#include <memory>

#include "LifeTimeControllerBase.h"
#include "RemoveParticleIfBorderReachedBase.h"
#include "ParticleSourceIface.h"

namespace phycoub
{

class BornPeriodLifeTimeController
    : public LifeTimeControllerBase
    , public RemoveParticleIfBorderReachedBase
{
  public:
    BornPeriodLifeTimeController( double bornPeriod, ParticleSourcePtr particleSource );
    virtual ~BornPeriodLifeTimeController() override = default;

    // Implementation of LifeTimeControllerIface
    virtual void phyControlLifeTime( double dt = 0. ) override;

    void setBornPeriod( double bornPeriod );
    double getBornPeriod() const;

  protected:
    // Implementation of RemoveParticleIfBorderReachedBase
    virtual ParticleGroupPtr getControlledParticleGroup() override;

  private:
    double bornPeriod_ = 0.;
    double currentPeriod = 0.;
};

using BornPeriodLifeTimeControllerPtr = std::shared_ptr< BornPeriodLifeTimeController >;

} // namespace phycoub