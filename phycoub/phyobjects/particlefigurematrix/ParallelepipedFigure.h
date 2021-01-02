/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:54:39
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 23:46:43
 */

#pragma once

#include <vector>

#include "Vector.h"
#include "BorderCondition.h"
#include "ParticleGroup.h"

namespace phycoub
{

class ParallelepipedFigure
{
  public:
    ParallelepipedFigure( const Vector& directionLine, const Vector& directionPlane,
        const Vector& directionParallelepiped, int numInLine, int numLineInPlane,
        int numPlaneInParallelepiped, const Vector& coordinate, const Vector& speed,
        double m, double z );
    virtual ~ParallelepipedFigure() = default;

    ParticleGroupPtr allParticles_ = std::make_shared< ParticleGroup >();
    ParticleGroupPtr centrallParticles_ = std::make_shared< ParticleGroup >();
    ParticleGroupPtr borderParticles_ = std::make_shared< ParticleGroup >();
};

} // namespace phycoub
