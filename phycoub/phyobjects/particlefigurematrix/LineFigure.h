/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-26 01:24:23
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 12:27:16
 */

#pragma once

#include "Vector.h"
#include "ParticleGroup.h"
#include "BorderCondition.h"

#include <vector>

namespace phycoub
{

class LineFigure
{
  public:
    LineFigure( const Vector& direction, int num, const Vector& coordinate,
        const Vector& speed, double m, double z );
    virtual ~LineFigure() = default;

    ParticleGroupPtr particles_ = std::make_shared< ParticleGroup >();
};

} // namespace phycoub
