/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-28 16:05:28
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-28 17:11:24
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

void InterworkingCalculatorBase::addGroupParticle( ParticleGroupPtr particles )
{
    particleGroupList_.push_back( particles );
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

const ParticleGroupList& InterworkingCalculatorBase::getParticleGroupList()
{
    return particleGroupList_;
}

} // namespace phycoub