/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:59:49
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 01:24:13
 */

#pragma once

#include <vector>

#include "Vector.h"
#include "BorderCondition.h"
#include "ParticleGroup.h"

namespace phycoub
{

class PlaneFigure
{
  public:
    PlaneFigure( const Vector& directionLine, const Vector& directionPlane, int numInLine,
        int numLineInPlane, const Vector& coordinate, const Vector& speed, double m,
        double z );
    virtual ~PlaneFigure() = default;

    ParticleGroupPtr allParticles_ = std::make_shared< ParticleGroup >();
    ParticleGroupPtr centrallParticles_ = std::make_shared< ParticleGroup >();
    ParticleGroupPtr borderParticles_ = std::make_shared< ParticleGroup >();
};

} // namespace phycoub
