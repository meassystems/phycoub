/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-04 14:06:27
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 13:41:54
 */

#pragma once

#include <memory>

#include "BorderCondition.h"
#include "BorderReachedEventGenerator.h"
#include "CylindricShape.h"

namespace phycoub
{

class CylinderBorderCondition
    : public BorderCondition
    , public BorderReachedEventGenerator
    , public CylindricShape
{
  public:
    CylinderBorderCondition( double radius, double height );
    virtual ~CylinderBorderCondition() override = default;

    // Implementation of BorderCondition
    virtual void psyMove(
        const Vector& move, const Vector& speed, ParticlePtr particle ) override;
};

using CylinderBorderConditionPtr = std::shared_ptr< CylinderBorderCondition >;

} // namespace phycoub