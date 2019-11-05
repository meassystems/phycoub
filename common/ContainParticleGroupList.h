/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-11-05 23:16:53
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-06 00:02:37
 */

#include "ContainParticleGroupIface.h"

#pragma once

namespace phycoub
{

class ContainParticleGroupList : public ContainParticleGroupIface
{
  public:
    ContainParticleGroupList() = default;
    virtual ~ContainParticleGroupList() = default;

    virtual void addParticleGroup( ParticleGroupPtr particleGroup ) override;
    virtual void removeParticleGroup( IDType id ) override;

  protected:
    ParticleGroupList* getParticleGroupList();

  private:
    ParticleGroupList particleGroupList;
};

} // namespace phycoub