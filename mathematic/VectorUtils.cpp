/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 16:30:01
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-10 20:53:27
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
double VectorUtils::scalarMultiplication( const Vector& first, const Vector& second )
{
    double result = first.x_ * second.x_ + first.y_ * second.y_ + first.z_ * second.z_;
    return result;
}

// static
double VectorUtils::projectionToVector( const Vector& distance, const Vector& source )
{
    double result = scalarMultiplication( distance, source ) / distance.getModule();
    return result;
}

} // namespace phycoub