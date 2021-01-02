/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-11-05 23:12:14
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-12 00:33:46
 */

#pragma once

#include <memory>
#include <list>

#include "ParticleGroupList.h"

namespace phycoub
{
/*
 * Интерфес для сущностей которые содержат список групп частиц
 */
class ContainParticleGroupIface
{
  public:
    ContainParticleGroupIface() = default;
    virtual ~ContainParticleGroupIface() = default;

    virtual void addParticleGroup( ParticleGroupPtr particleGroup ) = 0;
    virtual void removeParticleGroup( IDType id ) = 0;
    virtual void removeParticleGroup( ParticleGroupPtr particleGroup ) = 0;

    virtual void removeParticle( IDType id ) = 0;
    virtual void removeParticle( ParticlePtr particle ) = 0;

    virtual ParticleGroupList getParticleGroupList() = 0;
};

using ContainParticleGroupPtr = std::shared_ptr< ContainParticleGroupIface >;
using ContainParticleGroupPtrList = std::list< ContainParticleGroupPtr >;

} // namespace phycoub