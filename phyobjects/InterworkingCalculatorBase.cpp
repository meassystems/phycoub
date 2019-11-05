/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-28 16:05:28
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-05 23:56:37
 */

#include "InterworkingCalculatorBase.h"

namespace phycoub
{

InterworkingCalculatorBase::InterworkingCalculatorBase(
    InterworkingPtr interworking, std::string fieldName )
    : interworking_( interworking )
    , fieldName_( fieldName )
{
}

void InterworkingCalculatorBase::setInterworkingFunction(
    InterworkingPtr interworkingFunction )
{
    interworking_ = interworkingFunction;
}

InterworkingPtr InterworkingCalculatorBase::getInterworkingFunction()
{
    return interworking_;
}

} // namespace phycoub