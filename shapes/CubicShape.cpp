/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-04 14:20:51
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-04 14:23:20
 */

#include "CubicShape.h"

namespace phycoub
{

CubicShape::CubicShape( const Vector& borders )
    : borders_( borders )
{
}

void CubicShape::setBorders( const Vector& borders )
{
    borders_ = borders;
}

const Vector& CubicShape::getBorders() const
{
    return borders_;
}

} // namespace phycoub