/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-05 01:47:13
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 23:52:09
 */

#include "CylindricalXYParticleSource.h"

#include <math.h>

#include "RandomUtils.h"

namespace phycoub
{

CylindricalXYPartcleSource::CylindricalXYPartcleSource( double radius, double height,
    const Vector& sourceCoordinate, const ParticleOptions& particleOptions,
    double energy )
    : ParticleSourceBase( sourceCoordinate, particleOptions, energy )
    , CylindricShape( radius, height )
{
    setSourceCordinate( sourceCoordinate );
}

// virtual override
void CylindricalXYPartcleSource::setSourceCordinate( const Vector& sourceCoordinate )
{
    ParticleSourceBase::setSourceCordinate(
        Vector{ sourceCoordinate.x_, sourceCoordinate.y_, 0 } );
}

// virtual override
ParticlePtr CylindricalXYPartcleSource::phyGiveBirthParticle()
{
    const double squaredRadius = getSquaredRadius();
    const Vector xyDirection = RandomUtils::generateXYDirection();
    const double z = getHeight() * RandomUtils::generateNormalizedDouble();

    const Vector& sourceCoordinate = getSourceCoordinate();
    const ParticleOptions& particleOptions = getParticleOptions();
    const double speedFactor = getSpeedFactor();

    const Vector speed = xyDirection * speedFactor;
    const Vector coordinate = xyDirection * squaredRadius
        + Vector{ sourceCoordinate.x_, sourceCoordinate.y_, z };

    return std::make_shared< Particle >( coordinate, speed, particleOptions );
}

} // namespace phycoub