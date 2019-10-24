/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 19:08:35
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-23 19:21:42
 */

#include "HomogeneousField.h"

#include "VectorUtils.h"

namespace phycoub
{

HomogeneousField::HomogeneousField( const Vector& direction )
    : direction_( VectorUtils::normalizeVector( direction ) )
{
}

void HomogeneousField::setDirection( const Vector& direction )
{
    direction_ = VectorUtils::normalizeVector( direction );
}

const Vector& HomogeneousField::getDirection() const
{
    return direction_;
}

} // namespace phycoub