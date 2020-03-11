/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-26 09:57:56
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 16:53:05
 */

#include <algorithm>

#include "CalculationModel.h"
#include "Vector.h"
#include "FieldReceiver.h"
#include "CalculationGroup.h"

namespace phycoub
{

// virtual
void CalculationModel::phyCalculate( BorderConditionPtr borderCondition, double dt,
    const ParticleGroupList& particleGroupList )
{
    particleGroupList.forEachParticle( [borderCondition, dt]( ParticlePtr particle ) {
        const Vector speed = particle->getSpeed()
            + particle->resultant_ * ( dt / particle->getOptions().m_ );

        borderCondition->psyMove( speed * dt, speed, &particle );
    } );
}

} // namespace phycoub
