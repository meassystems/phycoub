/*
 * HighSpeedModificationVerle.h
 *
 *  Created on: Oct 20, 2016
 *      Author: root
 */

#ifndef HIGHSPEEDMODIFICATIONVERLE_H_
#define HIGHSPEEDMODIFICATIONVERLE_H_

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

    virtual void phyCalculate( ParticleGroupList* particleGroupList,
        BorderConditionPtr borderCondition, double dt ) override;
};

} /* namespace phycoub */

#endif /* HIGHSPEEDMODIFICATIONVERLE_H_ */
