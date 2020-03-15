/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-26 10:13:55
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 13:44:11
 */

#include <HighSpeedModificationVerle.h>
#include <algorithm>
#include <thread>
#include <functional>
#include "Vector.h"
#include "CalculationGroup.h"

#include <math.h>

namespace phycoub
{

// virtual override
void HighSpeedModificationVerle::phyCalculate( BorderConditionPtr borderCondition,
    double dt, const ParticleGroupList& particleGroupList )
{
    particleGroupList.forEachParticle( [borderCondition, dt]( ParticlePtr particle ) {
        const ParticleOptions& particleOptions = particle->getOptions();
        const Vector speed = particle->getSpeed()
            + ( particle->resultant_ + particle->previesResultant_ )
                * ( dt / ( particleOptions.m_ * 2 ) );

        borderCondition->psyMove( particle->previesSpeed_ * dt
                + particle->previesResultant_ * pow( dt, 2 ) / ( 2 * particleOptions.m_ ),
            speed, particle );
    } );
}

} // namespace phycoub
