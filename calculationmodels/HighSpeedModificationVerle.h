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
    HighSpeedModificationVerle();
    virtual ~HighSpeedModificationVerle();

    virtual void phyCalculate( CalculationGroup *calculationGroup );
};

} /* namespace phycoub */

#endif /* HIGHSPEEDMODIFICATIONVERLE_H_ */
