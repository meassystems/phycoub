/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 14:14:39
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-27 11:47:18
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

    virtual const Vector psyForce(
        const Vector& field, const ParticlePtr particle ) override;
};

using LDInterworkingPtr = std::shared_ptr< LDInterworking >;

} // namespace phycoub
