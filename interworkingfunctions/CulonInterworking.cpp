/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:32:23
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-10 20:49:02
 */

#include <CulonInterworking.h>
#include "math.h"

namespace phycoub
{

// virtual override
const Vector CulonInterworking::psyForce(
    const Vector& field, const ParticlePtr particle )
{
    const Vector force = field * particle->getOptions().q_;
    return force;
}

} // namespace phycoub
