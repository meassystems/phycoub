/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-15 23:59:52
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-30 10:40:29
 */

#include "ConeParticleSource.h"

#include <math.h>

#include "RandomUtils.h"
#include "VectorUtils.h"

namespace phycoub
{

ConeParticleSource::ConeParticleSource( const Vector& guideCosines, double heigth,
    double angle, const Vector& sourceCoordinate, const ParticleOptions& particleOptions,
    double energy )
    : ParticleSourceBase( sourceCoordinate, particleOptions, energy )
    , ConeShape( heigth, angle )
    , guideCosines_( guideCosines )
{
    setGuideCosines( guideCosines );
}

void ConeParticleSource::setGuideCosines( const Vector& guideCosines )
{
    guideCosines_ = VectorUtils::normalizeVector( guideCosines );

    const Vector zRotationCosines{ 1, 1,
        guideCosines_.x_ ? guideCosines_.x_
                / sqrt( pow( guideCosines.x_, 2 ) + pow( guideCosines_.y_, 2 ) )
                         : 0 };

    int zSign = guideCosines_.y_ != 0 ? guideCosines_.y_ / abs( guideCosines_.y_ ) : 1;
    const Vector zRotationSinuses{ 0, 0,
        (double)zSign * sqrt( 1 - pow( zRotationCosines.z_, 2 ) ) };

    zRotationMatrix_.setRotationCosines( zRotationCosines );
    zRotationMatrix_.setRotationSinuses( zRotationSinuses );

    const double xyProjection
        = sqrt( pow( guideCosines_.x_, 2 ) + pow( guideCosines_.y_, 2 ) );
    const Vector yRotationCosines{ 1,
        xyProjection ? xyProjection
                / sqrt( pow( guideCosines.x_, 2 ) + pow( guideCosines_.y_, 2 )
                    + pow( guideCosines_.z_, 2 ) )
                     : 0,
        1 };

    int ySign = guideCosines_.z_ != 0 ? guideCosines_.z_ / abs( guideCosines_.z_ ) : 1;
    /*
        Минус 1 перед знаком получена имперически
     */
    const Vector yRotationSinuses{ 0,
        -1 * (double)ySign * sqrt( 1 - pow( yRotationCosines.y_, 2 ) ), 0 };

    yRotationMatrix_.setRotationCosines( yRotationCosines );
    yRotationMatrix_.setRotationSinuses( yRotationSinuses );
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
    yRotationMatrix_.rotateVector( &randomDirectionGuideCosines );
    zRotationMatrix_.rotateVector( &randomDirectionGuideCosines );

    const Vector& sourceCoordinate = getSourceCoordinate();
    const ParticleOptions& particleOptions = getParticleOptions();
    const double speedFactor = getSpeedFactor();

    const Vector speed = randomDirectionGuideCosines * speedFactor;
    return std::make_shared< Particle >( sourceCoordinate, speed, particleOptions );
}

} // namespace phycoub