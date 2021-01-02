/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-27 11:46:03
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-10 20:58:46
 */

#include "MagneticInterworking.h"

namespace phycoub
{

const Vector MagneticInterworking::psyForce(
    const Vector& field, const ParticlePtr particle )
{
    const Vector force = ( particle->getSpeed() * field ) * particle->getOptions().q_;
    return force;
}

} // namespace phycoub