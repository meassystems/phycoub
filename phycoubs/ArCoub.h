/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 14:54:13
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 15:32:31
 */

#pragma once

#include <vector>
#include <math.h>

#include "PhyCoub.h"
#include "Vector.h"
#include "Particle.h"
#include "CreateField.h"
#include "FeelField.h"
#include "CalculationGroup.h"
#include "ThermostatBorder.h"
#include "BorderFieldCondition.h"
#include "LeapFrog.h"
#include "LDFieldFunction.h"
#include "LDInterworking.h"
#include "ParallelepipedFigure.h"

namespace phycoub
{

class ArCoub final : public PhyCoub
{
  public:
    ArCoub();
    virtual ~ArCoub();

    double dt_ = 1E-15, k_ = 1.38E-23, z_ = 0.0, temp = 500.0;
    double mAr_ = 6.6E-26, epsAr_ = 1.67E-21, aAr_ = 3.4E-10, radiusCut_ = 2.5 * aAr_;
    Vector borders_{ aAr_ * 20 * pow( 2, 1 / 6. ) };

    std::vector< Particle* > argon_;
    ParallelepipedFigure parallelepipedFigure{ Vector( 0, 0, aAr_* pow( 2, 1 / 6. ) ),
        Vector( 0, aAr_* pow( 2, 1 / 6. ), 0 ), Vector( aAr_* pow( 2, 1 / 6. ), 0, 0 ), 5,
        21, 21, Vector( 0 ), Vector( 0 ), mAr_, z_, &thermostatBorder };

  private:
    ThermostatBorder thermostatBorder{ &borders_, &k_, &temp };
    BorderFieldCondition borderFieldCondition_;

    LeapFrog leapFrog_;
    CalculationGroupPtr leapFrogCalculationGroup_
        = std::make_shared< CalculationGroup >( &leapFrog_, &dt_ );

    LDFieldFunction argonField_{ aAr_, aAr_, epsAr_ };
    CreateFieldPtr argonFieldCreator_ = std::make_shared< CreateField >(
        &argonField_, &borderFieldCondition_, "LD Argon Field" );
    LDInterworking argontInterworking_;
    FeelFieldPtr argonFieldResponsive_ = std::make_shared< FeelField >(
        argonFieldCreator_, &argontInterworking_, "LD Argon Feel" );
};

} // namespace phycoub
