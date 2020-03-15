/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-15 23:59:52
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-16 00:37:35
 */

#include "ConeParticleSource.h"

#include <math.h>

#include "RandomUtils.h"

namespace phycoub
{

ConeParticleSource::ConeParticleSource( const Vector& guideCosines, double heigth,
    double angle, const Vector& sourceCoordinate, const ParticleOptions& particleOptions,
    double energy )
    : ParticleSourceBase( sourceCoordinate, particleOptions, energy )
    , ConeShape( heigth, angle )
    , guideCosines_( guideCosines )
    , rotationMatrix_( guideCosines_ )
{
}

void ConeParticleSource::setGuideCosines( const Vector& guideCosines )
{
    guideCosines_ = guideCosines;
    rotationMatrix_.setGuideCosines( guideCosines_ );
}

const Vector& ConeParticleSource::getGuideCosines() const
{
    return guideCosines_;
}

// virtual override
ParticlePtr ConeParticleSource::phyGiveBirthParticle()
{
    const double tanDeviasionNagle
        = tan( getAngle() * RandomUtils::generateNormalizedDouble() );

    const double sinRotationAngle
        = RandomUtils::generateNormalizedDouble() * RandomUtils::getRandomSign();

    const double cosRotationAngle = sqrt( 1 - pow( sinRotationAngle, 2 ) );

    // cone system coordinate
    Vector randomDirectionGuideCosines{ 1, tanDeviasionNagle * sinRotationAngle,
        tanDeviasionNagle * cosRotationAngle };

    // transform vector from cone coordinate to coub coordinate
    rotationMatrix_.rotateVector( &randomDirectionGuideCosines );

    const Vector& sourceCoordinate = getSourceCoordinate();
    const ParticleOptions& particleOptions = getParticleOptions();
    const double speedFactor = getSpeedFactor();

    const Vector speed = randomDirectionGuideCosines * speedFactor;
    return std::make_shared< Particle >( sourceCoordinate, speed, particleOptions );
}

} // namespace phycoub