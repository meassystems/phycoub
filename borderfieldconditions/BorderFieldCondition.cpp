/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-24 19:54:37
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 19:10:07
 */

#include "BorderFieldCondition.h"

#include <algorithm>

namespace phycoub
{

// virtual
Vector BorderFieldCondition::phyFieldWithBorderCondition(
    FieldPtr field, const ParticlePtr particle, const Vector& mark )
{
    const Vector result = field->psyField( mark, particle );
    return result;
}

} // namespace phycoub
