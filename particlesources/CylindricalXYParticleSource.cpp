/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-05 01:47:13
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-09 19:11:55
 */

#include "CylindricalXYParticleSource.h"

#include <random>
#include <math.h>

namespace phycoub
{

CylindricalXYPartcleSource::CylindricalXYPartcleSource( double radius, double height,
    double energy, double particleWeight, double particleCharge,
    const Vector& sourceCoordinate )
    : CylindricShape( radius, height )
    , energy_( energy )
    , particleWeight_( particleWeight )
    , particleCharge_( particleCharge )
    , sourceCoordinate_( Vector{ sourceCoordinate.x_, sourceCoordinate.y_, 0 } )
{
    speedFactor_ = sqrt( 2 * energy_ / particleWeight_ );
}

// virtual override
ParticlePtr CylindricalXYPartcleSource::phyGiveBirthParticle()
{
    const double squaredRadius = getSquaredRadius();
    const Vector xyDirection = generateXYDirection();
    const double z = getHeight() * generateNormalizedDouble();

    const Vector speed = xyDirection * speedFactor_;
    const Vector coordinate = xyDirection * squaredRadius
        + Vector{ sourceCoordinate_.x_, sourceCoordinate_.y_, z };

    return std::make_shared< Particle >(
        coordinate, speed, particleWeight_, particleCharge_ );
}

void CylindricalXYPartcleSource::setEnergy( double energy )
{
    energy_ = energy;
    speedFactor_ = sqrt( 2 * energy_ / particleWeight_ );
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

// static
double CylindricalXYPartcleSource::generateNormalizedDouble()
{
    static std::random_device device;
    static std::mt19937 generator( device() );
    static std::uniform_real_distribution< double > distribution( 0., 1. );

    return distribution( generator );
}

// static
double CylindricalXYPartcleSource::getRandomSign()
{
    if ( generateNormalizedDouble() >= 0.5 )
    {
        return 1.;
    }

    return -1.;
}

// static
Vector CylindricalXYPartcleSource::generateXYDirection()
{
    const double x = generateNormalizedDouble() * getRandomSign();
    const double y = sqrt( 1 - pow( x, 2 ) ) * getRandomSign();
    return Vector{ x, y, 0 };
}

} // namespace phycoub