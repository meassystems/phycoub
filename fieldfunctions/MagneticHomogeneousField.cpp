/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 19:24:08
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-27 12:20:12
 */

#include "MagneticHomogeneousField.h"

namespace phycoub
{

MagneticHomogeneousField::MagneticHomogeneousField( const Vector& direction, double B )
    : HomogeneousField( direction )
    , B_( B )
{
}

// virtual override
Vector MagneticHomogeneousField::psyField(
    const Vector& mark, const ParticlePtr particle /* = nullptr*/ ) const
{
    const Vector field = getDirection() * B_;
    return field;
}

void MagneticHomogeneousField::setMagneticInduction( double B )
{
    B_ = B;
}

double MagneticHomogeneousField::getMagneticInduction() const
{
    return B_;
}

} // namespace phycoub