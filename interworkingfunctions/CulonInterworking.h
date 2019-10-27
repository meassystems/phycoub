/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-26 11:38:48
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-27 11:47:36
 */

#pragma once

#include <memory>

#include "InterworkingIface.h"

namespace phycoub
{
/*
 * Кулоновская сила
 */
class CulonInterworking : public InterworkingIface
{
  public:
    CulonInterworking() = default;
    virtual ~CulonInterworking() = default;

    virtual const Vector psyForce(
        const Vector& field, const ParticlePtr particle ) override;
};

using CulonInterworkingPtr = std::shared_ptr< CulonInterworking >;

} // namespace phycoub
