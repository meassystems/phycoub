/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 19:13:18
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 12:29:37
 */

#include "CalculationGroup.h"

#include <algorithm>

namespace phycoub
{

CalculationGroup::CalculationGroup(
    CalculationModelPtr calculatiomModel, BorderConditionPtr borderCondition )
    : calculationModel_( calculatiomModel )
    , borderCondition_( borderCondition )
{
}

void CalculationGroup::phyModeling( double dt )
{
    calculationModel_->phyCalculate( borderCondition_, dt, &particleGroupList_ );
}

void CalculationGroup::addGroupParticle( ParticleGroupPtr particles )
{
    particleGroupList_.emplace_back( particles );
}

} // namespace phycoub
