/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-15 23:23:56
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 23:35:52
 */

#include "ParticleSourceBase.h"

#include <math.h>

namespace phycoub
{

ParticleSourceBase::ParticleSourceBase( const Vector& sourceCoordinate,
    const ParticleOptions& particleOptions, double energy )
    : sourceCoordinate_( sourceCoordinate )
    , particleOptions_( particleOptions )
    , energy_( energy )
{
    updateSpeedFactor();
}

void ParticleSourceBase::setSourceCordinate( const Vector& sourceCoordinate )
{
    sourceCoordinate_ = sourceCoordinate;
}

const Vector& ParticleSourceBase::getSourceCoordinate() const
{
    return sourceCoordinate_;
}

void ParticleSourceBase::setParticleOptions( const ParticleOptions& particleOptions )
{
    particleOptions_ = particleOptions;
    updateSpeedFactor();
}

const ParticleOptions& ParticleSourceBase::getParticleOptions() const
{
    return particleOptions_;
}

void ParticleSourceBase::setEnergy( double energy )
{
    energy_ = energy;
    updateSpeedFactor();
}

double ParticleSourceBase::getEnergy() const
{
    return energy_;
}

double ParticleSourceBase::getSpeedFactor() const
{
    return speedFactor_;
}

void ParticleSourceBase::updateSpeedFactor()
{
    speedFactor_ = sqrt( 2 * energy_ / particleOptions_.m_ );
}

} // namespace phycoub