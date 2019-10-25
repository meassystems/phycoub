/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 14:15:20
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 14:15:42
 */

#include <LDInterworking.h>

namespace phycoub
{

const Vector LDInterworking::psyForce( const Vector& field, const Particle* particle )
{
    return field;
}

} // namespace phycoub
