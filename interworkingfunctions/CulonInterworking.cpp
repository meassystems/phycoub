/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:32:23
 * @Last Modified by:   Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 18:32:23
 */

#include <CulonInterworking.h>
#include "math.h"

namespace phycoub
{

const Vector CulonInterworking::psyForce(
    const Vector& field, const ParticlePtr particle )
{
    return field * particle->z_;
}

} // namespace phycoub
