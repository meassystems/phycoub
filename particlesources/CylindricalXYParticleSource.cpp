/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-05 01:47:13
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 22:32:41
 */

#include "CylindricalXYParticleSource.h"

#include <math.h>

#include "RandomUtils.h"

namespace phycoub
{

CylindricalXYPartcleSource::CylindricalXYPartcleSource( double radius, double height,
    double energy, double particleWeight, double particleCharge,
    const Vector& sourceCoordinate )
    : CylindricShape( radius, height )
    , energy_( energy )
    , particleOptions( particleWeight, particleCharge )
    , sourceCoordinate_( Vector{ sourceCoordinate.x_, sourceCoordinate.y_, 0 } )
{
    speedFactor_ = sqrt( 2 * energy_ / particleOptions.m_ );
}

// virtual override
ParticlePtr CylindricalXYPartcleSource::phyGiveBirthParticle()
{
    const double squaredRadius = getSquaredRadius();
    const Vector xyDirection = RandomUtils::generateXYDirection();
    const double z = getHeight() * RandomUtils::generateNormalizedDouble();

    const Vector speed = xyDirection * speedFactor_;
    const Vector coordinate = xyDirection * squaredRadius
        + Vector{ sourceCoordinate_.x_, sourceCoordinate_.y_, z };

    return std::make_shared< Particle >( coordinate, speed, particleOptions );
}

void CylindricalXYPartcleSource::setEnergy( double energy )
{
    energy_ = energy;
    speedFactor_ = sqrt( 2 * energy_ / particleOptions.m_ );
}

double CylindricalXYPartcleSource::getEnergy() const
{
    return energy_;
}

void CylindricalXYPartcleSource::setSourceCordinate( const Vector& sourceCoordinate )
{
    sourceCoordinate_ = Vector{ sourceCoordinate.x_, sourceCoordinate.y_, 0 };
}

const Vector& CylindricalXYPartcleSource::getSourceCoordinate() const
{
    return sourceCoordinate_;
}

} // namespace phycoub