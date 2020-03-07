/*
 * FigureDemonstration.h
 *
 *  Created on: Dec 22, 2016
 *      Author: root
 */

#pragma once

#include "PhyCoub.h"
#include "Vector.h"
#include "ElasticCoubCondition.h"
#include "LineFigure.h"
#include "PlaneFigure.h"
#include "ParallelepipedFigure.h"

#include <math.h>

namespace phycoub
{

class FigureDemonstration final : public PhyCoub
{
  public:
    FigureDemonstration();
    virtual ~FigureDemonstration() = default;

    virtual void phyCoub() override;

    double dt_ = 1E-15, k_ = 1.38E-23, z_ = 0.;
    double mN_ = 23.24E-27, epsN = 95.05 * k_, aN = 3.698E-10;
    double radiusCat_ = aN * 3;
    Vector borders_{ 1e-8 };

    LineFigure lineN{ Vector( 0, 0, aN * 2. ), 2, Vector( 5E-9 ), Vector( 0, 0, .0 ), mN_,
        z_ };
    PlaneFigure planeN{ Vector( 0, 0, aN* pow( 2, 1 / 6. ) ),
        Vector( 0, aN* pow( 2, 1 / 6. ), 0 ), 20, 20, Vector( 1E-9 ), Vector( 0, 0, 0 ),
        mN_, z_ };
    ParallelepipedFigure parallelepipedN{ Vector( 0, 0, aN* pow( 2, 1 / 6. ) ),
        Vector( 0, aN* pow( 2, 1 / 6. ), 0 ), Vector( aN* pow( 2, 1 / 6. ), 0, 0 ), 10,
        10, 10, Vector( 1E-9 ), Vector( 0, 0, 0 ), mN_, z_ };
};

} // namespace phycoub
