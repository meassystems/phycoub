/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 16:29:19
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 22:49:00
 */

#include "Particle.h"
#include "BorderCondition.h"

namespace phycoub
{

Particle::Particle()
    : coordinate_( 0., 0., 0. )
    , speed_( 0., 0., 0. )
    , m_( 0. )
    , z_( 0. )
{
    ++index;
    index_ = index;
}
Particle::Particle( const Vector& coordinate, const Vector& speed, double m, double z )
    : coordinate_( coordinate )
    , speed_( speed )
    , m_( m )
    , z_( z )
{
    ++index;
    index_ = index;
}

bool Particle::operator==( const Particle& particle )
{
    return this->index == particle.index;
}

void Particle::moved()
{
    previesResultant_ = resultant_;
    previesSpeed_ = speed_;
    previesCoordinate_ = coordinate_;

    resultant_ = 0;
}

long Particle::index( 0 );

} // namespace phycoub
