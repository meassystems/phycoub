/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-11-05 23:16:53
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-12 00:34:21
 */

#include "ContainParticleGroupIface.h"

#pragma once

namespace phycoub
{
/*
 * Базовая реализация для сущностей, которые содепжат лист групп частиц
 */
class ContainParticleGroupList : public ContainParticleGroupIface
{
  public:
    ContainParticleGroupList() = default;
    virtual ~ContainParticleGroupList() = default;

    virtual void addParticleGroup( ParticleGroupPtr particleGroup ) override;
    virtual void removeParticleGroup( IDType id ) override;
    virtual void removeParticleGroup( ParticleGroupPtr particleGroup ) override;

    virtual void removeParticle( IDType id ) override;
    virtual void removeParticle( ParticlePtr particle ) override;

    virtual ParticleGroupList getParticleGroupList() override;

  private:
    ParticleGroupList particleGroupList;
};

} // namespace phycoub