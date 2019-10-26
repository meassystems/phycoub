/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-24 19:54:37
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 09:05:56
 */

#include "BorderFieldCondition.h"

#include <algorithm>

namespace phycoub
{

// virtual
Vector BorderFieldCondition::phyFieldWithBorderCondition(
    FieldFunctionPtr fieldFunction, const ParticlePtr particle, const Vector& mark )
{
    const Vector result = fieldFunction->psyField( mark, particle );
    return result;
}

} /* namespace phycoub */
