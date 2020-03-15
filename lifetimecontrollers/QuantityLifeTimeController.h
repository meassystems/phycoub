/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-06 20:23:47
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 12:47:33
 */

#pragma once

#include <memory>

#include "LifeTimeControllerIface.h"
#include "BorderReachedObserver.h"
#include "ParticleSourceIface.h"
#include "ParticleGroup.h"
#include "ContainOneParticleGroup.h"

namespace phycoub
{
/*
 * Контроллер времени жизни частиц. При достижении частицой границ уничтожает ее и
 * пораждает новую из заданного источника
 */
class QuantityLifeTimeController
    : public LifeTimeControllerIface
    , public BorderReachedObserver
    , public ContainOneParticleGroup
{
  public:
    QuantityLifeTimeController(
        long lifeParticleCount, ParticleSourcePtr particleSource );
    virtual ~QuantityLifeTimeController() override = default;

    // Implementation of LifeTimeControllerIface
    virtual void phyControlLifeTime() override;

    // Implementation of BorderReachedObserver
    virtual void onBorderReached( ParticlePtr particle ) override;

    void setParticleGroup( ParticleGroupPtr particleGroup );

    long getLifeParticleCount() const;
    void setLifeParticleCount( long count );

  private:
    long lifeParticleCount_ = 0;
    ParticleSourcePtr particleSource_;
    ParticleGroupPtr particleGroupReachedBorder_;
};

using QuantityLifeTimeControllerPtr = std::shared_ptr< QuantityLifeTimeController >;

} // namespace phycoub