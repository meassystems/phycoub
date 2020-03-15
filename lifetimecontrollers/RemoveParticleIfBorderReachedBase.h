/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-16 01:39:22
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-16 02:37:52
 */

#pragma once

#include "BorderReachedObserver.h"
#include "ParticleGroup.h"

namespace phycoub
{

class RemoveParticleIfBorderReachedBase : public BorderReachedObserver
{
  public:
    RemoveParticleIfBorderReachedBase();
    virtual ~RemoveParticleIfBorderReachedBase() override = default;

    // Implementation of BorderReachedObserver
    virtual void onBorderReached( ParticlePtr particle ) override;

  protected:
    virtual ParticleGroupPtr getControlledParticleGroup() = 0;
    void removeReachedBorderParticles();

  private:
    ParticleGroupPtr particleGroupReachedBorder_;
};

} // namespace phycoub