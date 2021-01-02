/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-06 20:23:47
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-16 02:37:59
 */

#pragma once

#include <memory>

#include "LifeTimeControllerBase.h"
#include "RemoveParticleIfBorderReachedBase.h"

namespace phycoub
{
/*
 * Контроллер времени жизни частиц. При достижении частицой границ уничтожает ее и
 * пораждает новую из заданного источника
 */
class QuantityLifeTimeController
    : public LifeTimeControllerBase
    , public RemoveParticleIfBorderReachedBase

{
  public:
    QuantityLifeTimeController(
        long lifeParticleCount, ParticleSourcePtr particleSource );
    virtual ~QuantityLifeTimeController() override = default;

    long getLifeParticleCount() const;
    void setLifeParticleCount( long count );

    // Implementation of LifeTimeControllerIface
    virtual void phyControlLifeTime( double dt = 0. ) override;

  protected:
    // Implementation of RemoveParticleIfBorderReachedBase
    virtual ParticleGroupPtr getControlledParticleGroup() override;

  private:
    long lifeParticleCount_ = 0;
};

using QuantityLifeTimeControllerPtr = std::shared_ptr< QuantityLifeTimeController >;

} // namespace phycoub