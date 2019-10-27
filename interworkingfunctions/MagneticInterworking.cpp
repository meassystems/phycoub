/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-27 11:46:03
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-27 16:03:00
 */

#include "MagneticInterworking.h"
#include "VectorUtils.h"

namespace phycoub
{

const Vector MagneticInterworking::psyForce(
    const Vector& field, const ParticlePtr particle )
{
    const Vector force
        = VectorUtils::vectorMultiplication( particle->getSpeed(), field ) * particle->z_;
    return force;
}

} // namespace phycoub