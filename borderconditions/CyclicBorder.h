/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 22:21:14
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-04 14:24:12
 */

#pragma once

#include "BorderCondition.h"
#include "CubicShape.h"

namespace phycoub
{

class CyclicBorder
    : public BorderCondition
    , public CubicShape
{
  public:
    CyclicBorder( const Vector& borders );
    virtual ~CyclicBorder() = default;

    virtual void psyMove(
        const Vector& move, const Vector& speed, ParticlePtr* particle ) override;
};

using CyclicBorderPtr = std::shared_ptr< CyclicBorder >;

} // namespace phycoub
