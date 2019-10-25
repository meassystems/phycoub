/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 12:14:33
 * @Last Modified by:   Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 12:14:33
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

    virtual void phyCalculate( CalculationGroup* calculationGroup );
};

} // namespace phycoub
