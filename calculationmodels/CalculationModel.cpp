/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-26 09:57:56
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 10:08:58
 */

#include "../calculationmodels/CalculationModel.h"

#include <algorithm>
#include "Vector.h"
#include "FeelField.h"
#include "CalculationGroup.h"

namespace phycoub
{

// virtual
void CalculationModel::phyCalculate(
    BorderConditionPtr borderCondition, double dt, ParticleGroupList* particleGroupList )
{
    for ( ParticlePtr particle : *particleGroupList )
    {
        particle->speed_ += particle->resultant_ * ( dt / particle->m_ );
        borderCondition->psyMove( particle->speed_ * dt, &particle );
    }
}

} // namespace phycoub
