/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-26 11:38:48
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 11:46:13
 */

#pragma once

#include <memory>

#include "InterworkingFunction.h"

namespace phycoub
{
/*
 * Кулоновская сила
 */
class CulonInterworking : public InterworkingFunction
{
  public:
    CulonInterworking() = default;
    virtual ~CulonInterworking() = default;

    const Vector psyForce( const Vector& field, const ParticlePtr particle ) override;
};

using CulonInterworkingPtr = std::shared_ptr< CulonInterworking >;

} // namespace phycoub
