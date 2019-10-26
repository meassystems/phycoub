/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 12:14:33
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 10:13:05
 */

#pragma once

#include <CalculationModel.h>

namespace phycoub
{

class LeapFrog : public CalculationModel
{
  public:
    LeapFrog() = default;
    virtual ~LeapFrog() = default;

    virtual void phyCalculate( BorderConditionPtr borderCondition, double dt,
        ParticleGroupList* particleGroupList ) override;
};

using LeapFrogPtr = std::shared_ptr< LeapFrog >;

} // namespace phycoub
