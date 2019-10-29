/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:05:52
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-29 12:41:24
 */

#include "BorderCondition.h"
#include "Particle.h"

namespace phycoub
{

BorderCondition::BorderCondition( const Vector& borders )
    : borders_( borders )
{
}

void BorderCondition::psyMove(
    const Vector& move, const Vector& speed, ParticlePtr* particle )
{
    const Vector coordinate = ( *particle )->getCoordinate() + move;
    moveParticle( coordinate, speed, false, particle );
}

void BorderCondition::setBorders( const Vector& borders )
{
    borders_ = borders;
}

const Vector& BorderCondition::getBorders() const
{
    return borders_;
}

void BorderCondition::moveParticle( const Vector& coordinate, const Vector& speed,
    bool isBorderReached, ParticlePtr* particle )
{
    ( *particle )->move( coordinate, speed );
    // todo: twice becose if once - invalid result for calculation models uses previes
    // values
    if ( isBorderReached )
    {
        ( *particle )->move( coordinate, speed );
    }
}

} // namespace phycoub
