/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 16:29:19
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-12 00:48:50
 */

#include "Particle.h"

namespace phycoub
{

ParticleOptions::ParticleOptions( double m, double q )
    : m_( m )
    , q_( q )
{
}

Particle::Particle( const Vector& coordinate, const Vector& speed, double m, double q )
    : coordinate_( coordinate )
    , speed_( speed )
    , options_( m, q )
{
}

Particle::Particle(
    const Vector& coordinate, const Vector& speed, ParticleOptions options )
    : coordinate_( coordinate )
    , speed_( speed )
    , options_( options )
{
}

bool Particle::operator==( const Particle& particle )
{
    return getId() == particle.getId();
}

void Particle::move( const Vector& coordinate, const Vector& speed )
{
    previesResultant_ = resultant_;
    previesSpeed_ = speed_;

    resultant_ = 0;
    coordinate_ = coordinate;
    speed_ = speed;
}

const ParticleOptions& Particle::getOptions() const
{
    return options_;
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
