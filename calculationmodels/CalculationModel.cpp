/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-26 09:57:56
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-10 20:32:25
 */

#include <algorithm>

#include "CalculationModel.h"
#include "Vector.h"
#include "FieldReceiver.h"
#include "CalculationGroup.h"

namespace phycoub
{

// virtual
void CalculationModel::phyCalculate(
    BorderConditionPtr borderCondition, double dt, ParticleGroupList* particleGroupList )
{
    for ( ParticlePtr particle : *particleGroupList )
    {
        const Vector speed = particle->getSpeed()
            + particle->resultant_ * ( dt / particle->getOptions().m_ );
        borderCondition->psyMove( speed * dt, speed, &particle );
    }
}

} // namespace phycoub
