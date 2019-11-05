/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-11-05 23:12:14
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-06 00:31:01
 */

#include "ParticleGroup.h"

#pragma once

namespace phycoub
{

class ContainParticleGroupIface
{
  public:
    ContainParticleGroupIface() = default;
    virtual ~ContainParticleGroupIface() = default;

    virtual void addParticleGroup( ParticleGroupPtr particleGroup ) = 0;
    virtual void removeParticleGroup( IDType id ) = 0;
    virtual void removeParticleGroup( ParticleGroupPtr particleGroup ) = 0;
};

} // namespace phycoub