/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-26 10:13:35
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 01:52:30
 */

#pragma once

#include "CalculationModel.h"

namespace phycoub
{

class FieldReceiver;
/*
 * Методика расчета по скоростной модификации Верле.
 */
class HighSpeedModificationVerle : public CalculationModel
{
  public:
    HighSpeedModificationVerle() = default;
    virtual ~HighSpeedModificationVerle() = default;

    virtual void phyCalculate( BorderConditionPtr borderCondition, double dt,
        const ParticleGroupList& particleGroupList ) override;
};

} // namespace phycoub
