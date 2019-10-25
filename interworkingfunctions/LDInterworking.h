/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 14:14:39
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 18:32:47
 */

#pragma once

#include <InterworkingFunction.h>

namespace phycoub
{

class LDInterworking : public InterworkingFunction
{
  public:
    LDInterworking() = default;
    virtual ~LDInterworking() = default;

    const Vector psyForce( const Vector& field, const ParticlePtr particle );
};

} // namespace phycoub
