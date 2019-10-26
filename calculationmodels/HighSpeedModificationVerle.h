/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-26 10:13:35
 * @Last Modified by:   Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 10:13:35
 */

#pragma once

#include <CalculationModel.h>

namespace phycoub
{

class FeelField;
/*
 * Методика расчета по скоростной модификации Верле.
 */
class HighSpeedModificationVerle : public CalculationModel
{
  public:
    HighSpeedModificationVerle() = default;
    virtual ~HighSpeedModificationVerle() = default;

    virtual void phyCalculate( BorderConditionPtr borderCondition, double dt,
        ParticleGroupList* particleGroupList ) override;
};

} // namespace phycoub
