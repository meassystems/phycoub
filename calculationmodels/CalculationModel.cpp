/*
 * CalculationModel.cpp
 *
 *  Created on: 19 ���. 2016 �.
 *      Author: SFrancishkov
 */

#include "../calculationmodels/CalculationModel.h"

#include <algorithm>
#include "Vector.h"
#include "FeelField.h"
#include "CalculationGroup.h"

namespace phycoub
{

void CalculationModel::phyCalculate(
    ParticleGroupList* particleGroupList, BorderConditionPtr borderCondition, double dt )
{
    for ( ParticlePtr particle : *particleGroupList )
    {
        particle->speed_ += particle->resultant_ * ( dt / particle->m_ );
        borderCondition->psyMove( particle->speed_ * dt, &particle );
    }
}

} /* namespace phycoub */
