/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-15 23:59:52
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-30 11:39:45
 */

#include "ConeParticleSource.h"

#include <math.h>

#include "RandomUtils.h"
#include "VectorUtils.h"
#include "ProgrammingException.h"

namespace phycoub
{

ConeParticleSource::ConeParticleSource( const Vector& direction, double angle,
    const Vector& sourceCoordinate, const ParticleOptions& particleOptions,
    double energy )
    : ParticleSourceBase( sourceCoordinate, particleOptions, energy )
    , ConeShape( 1., angle )
    , _direction( direction )
    , _rotationMatrix( RotationMatrix::directionToRotation( direction ) )
{
    PROGRAMMING_ASSERT(angle < M_PI / 2);
}

void ConeParticleSource::setDirection( const Vector& direction )
{
    _direction = direction;
    _rotationMatrix = RotationMatrix( RotationMatrix::directionToRotation( direction ) );
}

const Vector& ConeParticleSource::getDirection() const
{
    return _direction;
}

// virtual override
ParticlePtr ConeParticleSource::phyGiveBirthParticle()
{
    double k = tan( getAngle() );

    double z = k * ( 2 * RandomUtils::generateNormalizedDouble() - 1 );
    double y = sqrt( pow( k, 2 ) - pow( z, 2 ) ) * RandomUtils::getRandomSign();
    double x = 1.;

    Vector randomInCone{ x, y, z };
    Vector randomInConeCartesianProjection = VectorUtils::normalizeVector( randomInCone );
    _rotationMatrix.rotateVector( &randomInConeCartesianProjection );

    const Vector& sourceCoordinate = getSourceCoordinate();
    const ParticleOptions& particleOptions = getParticleOptions();
    const double speedFactor = getSpeedFactor();

    const Vector speed = randomInConeCartesianProjection * speedFactor;
    return std::make_shared< Particle >( sourceCoordinate, speed, particleOptions );
}

} // namespace phycoub