/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 12:14:47
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 13:44:17
 */

#include <LeapFrog.h>

#include <algorithm>
#include <thread>
#include <functional>
#include "Vector.h"
#include "CalculationGroup.h"

namespace phycoub
{

// virtual override
void LeapFrog::phyCalculate( BorderConditionPtr borderCondition, double dt,
    const ParticleGroupList& particleGroupList )
{
    particleGroupList.forEachParticle( [borderCondition, dt]( ParticlePtr particle ) {
        const Vector speed = particle->getSpeed()
            + particle->resultant_ * ( dt / particle->getOptions().m_ );
        borderCondition->psyMove( speed * dt, speed, particle );
    } );
}

} // namespace phycoub
