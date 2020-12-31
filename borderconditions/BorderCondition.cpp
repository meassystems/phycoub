/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:05:52
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 13:41:20
 */

#include "BorderCondition.h"
#include "Particle.h"

namespace phycoub
{

void BorderCondition::psyMove(
    const Vector& move, const Vector& speed, ParticlePtr particle )
{
    const Vector coordinate = particle->getCoordinate() + move;
    moveParticle( coordinate, speed, false, particle );
}

void BorderCondition::moveParticle( const Vector& coordinate, const Vector& speed,
    bool isBorderReached, ParticlePtr particle )
{
    particle->move( coordinate, speed );
    // todo: twice becose if once - invalid result for calculation models uses previous values
    if ( isBorderReached )
    {
        particle->move( coordinate, speed );
    }
}

} // namespace phycoub
