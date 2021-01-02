/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 19:13:10
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-05 23:53:34
 */

#pragma once

#include <vector>
#include <list>
#include <memory>

#include "ContainParticleGroupList.h"
#include "Vector.h"
#include "ParticleGroup.h"
#include "CalculationModel.h"
#include "BorderCondition.h"

namespace phycoub
{

class CalculationGroup : public ContainParticleGroupList
{
  public:
    CalculationGroup(
        CalculationModelPtr calculatiomModel, BorderConditionPtr borderCondition );
    virtual ~CalculationGroup() = default;

    void phyModeling( double dt );

  private:
    CalculationModelPtr calculationModel_;
    BorderConditionPtr borderCondition_;
};

using CalculationGroupPtr = std::shared_ptr< CalculationGroup >;
using CalculationGroupList = std::list< CalculationGroupPtr >;

} // namespace phycoub
