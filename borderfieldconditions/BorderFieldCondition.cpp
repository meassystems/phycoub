/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-24 19:54:37
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-24 20:40:55
 */

#include "BorderFieldCondition.h"

#include <algorithm>

namespace phycoub
{

Vector BorderFieldCondition::phyFieldWithBorderCondition(
    FieldFunction* fieldFunction, const Particle& particle, const Vector& mark )
{
    const Vector result = fieldFunction->psyField( mark, &particle );
    return result;
}

} /* namespace phycoub */
