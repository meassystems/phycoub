/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-14 14:20:24
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-14 14:44:10
 */

#pragma once

#include "ContainParticleGroupIface.h"

namespace phycoub
{

class ContainOneParticleGroup : public ContainParticleGroupIface
{
  public:
    ContainOneParticleGroup() = default;
    virtual ~ContainOneParticleGroup() = default;

    ParticleGroupPtr getParticleGroup();

    virtual void addParticleGroup( ParticleGroupPtr particleGroup ) override;
    virtual void removeParticleGroup( IDType id ) override;
    virtual void removeParticleGroup( ParticleGroupPtr particleGroup ) override;

    virtual void removeParticle( IDType id ) override;
    virtual void removeParticle( ParticlePtr particle ) override;

    virtual ParticleGroupList getParticleGroupList() override;

  private:
    ParticleGroupList particleGroupList_;
};

} // namespace phycoub