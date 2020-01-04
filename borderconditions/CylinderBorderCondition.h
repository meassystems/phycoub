/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-04 14:06:27
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-05 01:57:49
 */

#pragma once

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
        const Vector& move, const Vector& speed, ParticlePtr* particle ) override;
};

} // namespace phycoub