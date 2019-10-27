/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-27 11:43:24
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-27 11:52:31
 */

#pragma once

#include <memory>

#include "InterworkingIface.h"

namespace phycoub
{

class MagneticInterworking final : public InterworkingIface
{
  public:
    MagneticInterworking() = default;
    virtual ~MagneticInterworking() = default;

    virtual const Vector psyForce(
        const Vector& field, const ParticlePtr particle ) override;
};

using MagneticInterworkingPtr = std::shared_ptr< MagneticInterworking >;

} // namespace phycoub