/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 19:08:35
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-12 23:22:17
 */

#include "DirectHomogeneousField.h"

#include "VectorUtils.h"

namespace phycoub
{

DirectHomogeneousField::DirectHomogeneousField( const Vector& direction )
    : direction_( VectorUtils::normalizeVector( direction ) )
{
}

// virtual override
Vector DirectHomogeneousField::getDirection( const Vector& mark /* = Vector{}*/ ) const
{
    return direction_;
}

void DirectHomogeneousField::setDirection( const Vector& direction )
{
    direction_ = VectorUtils::normalizeVector( direction );
}

} // namespace phycoub