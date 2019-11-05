/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 16:29:19
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-05 23:10:18
 */

#include "Particle.h"
#include "BorderCondition.h"

namespace phycoub
{

Particle::Particle( const Vector& coordinate, const Vector& speed, double m, double z )
    : coordinate_( coordinate )
    , previesCoordinate_( coordinate_ )
    , speed_( speed )
    , m_( m )
    , z_( z )
{
}

bool Particle::operator==( const Particle& particle )
{
    return getId() == particle.getId();
}

void Particle::move( const Vector& coordinate, const Vector& speed )
{
    previesResultant_ = resultant_;
    previesCoordinate_ = coordinate_;
    previesSpeed_ = speed_;

    resultant_ = 0;
    coordinate_ = coordinate;
    speed_ = speed;
}

const Vector& Particle::getCoordinate() const
{
    return coordinate_;
}

const Vector& Particle::getSpeed() const
{
    return speed_;
}

} // namespace phycoub
