/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 16:30:01
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-13 00:15:25
 */

#include "VectorUtils.h"

#include "Vector.h"

namespace phycoub
{

// static
Vector VectorUtils::normalizeVector( Vector vector )
{
    const double vectorModulo = vector.getModule();
    if ( vectorModulo == 0 )
    {
        return vector;
    }

    vector /= vectorModulo;
    return vector;
}

// static
Vector VectorUtils::vectorMultiplication( const Vector& first, const Vector& second )
{
    Vector resultVector( first.y_ * second.z_ - first.z_ * second.y_,
        first.z_ * second.x_ - first.x_ * second.z_,
        first.x_ * second.y_ - first.y_ * second.x_ );
    return resultVector;
}

} // namespace phycoub