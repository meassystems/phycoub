/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 19:24:08
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 18:29:03
 */

#include "MagneticHomogeneousField.h"

namespace phycoub
{

MagneticHomogeneousField::MagneticHomogeneousField(
    const Vector& direction, const Vector& B )
    : HomogeneousField( direction )
    , B_( B )
{
}

// virtual override
Vector MagneticHomogeneousField::psyField(
    const Vector& mark, const ParticlePtr particle /* = nullptr*/ ) const
{
    return B_;
}

void MagneticHomogeneousField::setMagneticInduction( const Vector& B )
{
    B_ = B;
}

const Vector& MagneticHomogeneousField::getMagneticInduction() const
{
    return B_;
}

} // namespace phycoub