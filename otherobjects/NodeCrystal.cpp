/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:33:40
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 23:15:03
 */

#include "NodeCrystal.h"

namespace phycoub
{

NodeCrystal::NodeCrystal()
    : Particle()
    , shag( 0 )
{
    ++index;
}
NodeCrystal::NodeCrystal(
    const Vector& coordinate, const Vector& speed, double m, double q )
    : Particle( coordinate, speed, m, q )
    , shag( 0 )
{
    ++index;
}

} /* namespace phycoub */
