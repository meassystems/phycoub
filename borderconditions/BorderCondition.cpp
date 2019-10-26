/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:05:52
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 08:20:23
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
    const Vector& move, const Vector& newSpeed, ParticlePtr* particle )
{
    Vector coordinate = ( *particle )->getCoordinate();
    coordinate += move;
    ( *particle )->move( coordinate, newSpeed );
}

void BorderCondition::setBorders( const Vector& borders )
{
    borders_ = borders;
}

const Vector& BorderCondition::getBorders() const
{
    return borders_;
}

} // namespace phycoub
