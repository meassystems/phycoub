/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 14:14:39
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 18:53:51
 */

#pragma once

#include <memory>

#include "InterworkingIface.h"

namespace phycoub
{

class LDInterworking : public InterworkingIface
{
  public:
    LDInterworking() = default;
    virtual ~LDInterworking() = default;

    const Vector psyForce( const Vector& field, const ParticlePtr particle );
};

using LDInterworkingPtr = std::shared_ptr< LDInterworking >;

} // namespace phycoub
