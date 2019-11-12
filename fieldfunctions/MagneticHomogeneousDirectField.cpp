/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 19:24:08
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-12 23:18:20
 */

#include "MagneticHomogeneousDirectField.h"

namespace phycoub
{

MagneticHomogeneousDirectField::MagneticHomogeneousDirectField(
    const Vector& direction, double B )
    : DirectHomogeneousField( direction )
    , B_( B )
{
}

// virtual override
Vector MagneticHomogeneousDirectField::psyField(
    const Vector& mark, const ParticlePtr particle /* = nullptr*/ ) const
{
    const Vector field = getDirection() * B_;
    return field;
}

void MagneticHomogeneousDirectField::setMagneticInduction( double B )
{
    B_ = B;
}

double MagneticHomogeneousDirectField::getMagneticInduction() const
{
    return B_;
}

} // namespace phycoub