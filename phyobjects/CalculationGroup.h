/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 19:13:10
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 10:11:10
 */

#pragma once

#include <vector>
#include <list>
#include <memory>

#include "Vector.h"
#include "ParticleGroup.h"
#include "CalculationModel.h"
#include "BorderCondition.h"

namespace phycoub
{

class CalculationGroup
{
  public:
    CalculationGroup(
        CalculationModelPtr calculatiomModel, BorderConditionPtr borderCondition );
    virtual ~CalculationGroup() = default;

    void phyModeling( double dt );

    void addGroupParticle( ParticleGroupPtr particles );

  private:
    CalculationModelPtr calculationModel_;
    BorderConditionPtr borderCondition_;
    ParticleGroupList particleGroupList_;
};

using CalculationGroupPtr = std::shared_ptr< CalculationGroup >;
using CalculationGroupList = std::list< CalculationGroupPtr >;

} // namespace phycoub
