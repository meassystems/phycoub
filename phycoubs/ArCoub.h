/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 14:54:13
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 13:59:48
 */

#pragma once

#include <vector>
#include <math.h>

#include "PhyCoub.h"
#include "Vector.h"
#include "ParticleGroup.h"
#include "DynamicFieldCreator.h"
#include "FieldReceiver.h"
#include "CalculationGroup.h"
#include "ThermostatBorder.h"
#include "BorderFieldCondition.h"
#include "LeapFrog.h"
#include "LDField.h"
#include "LDInterworking.h"
#include "ParallelepipedFigure.h"

namespace phycoub
{

class ArCoub final : public PhyCoub
{
  public:
    ArCoub();
    virtual ~ArCoub() = default;

    const Vector& getBorders() const;

    double dt_ = 1E-15, k_ = 1.38E-23, z_ = 0.0, temp = 500.0;
    double mAr_ = 6.6E-26, epsAr_ = 1.67E-21, aAr_ = 3.4E-10, radiusCut_ = 2.5 * aAr_;

    ParallelepipedFigure parallelepipedFigure{ Vector( 0, 0, aAr_* pow( 2, 1 / 6. ) ),
        Vector( 0, aAr_* pow( 2, 1 / 6. ), 0 ), Vector( aAr_* pow( 2, 1 / 6. ), 0, 0 ), 5,
        21, 21, Vector( 0 ), Vector( 0 ), mAr_, z_ };

  private:
    ThermostatBorderPtr thermostatBorder_ = std::make_shared< ThermostatBorder >(
        Vector{ aAr_ * 20 * pow( 2, 1 / 6. ) }, k_, temp );
    BorderFieldConditionPtr borderFieldCondition_
        = std::make_shared< BorderFieldCondition >();

    LeapFrogPtr leapFrog_ = std::make_shared< LeapFrog >();
    CalculationGroupPtr leapFrogCalculationGroup_
        = std::make_shared< CalculationGroup >( leapFrog_, thermostatBorder_ );

    LDFieldPtr argonField_ = std::make_shared< LDField >( aAr_, aAr_, epsAr_ );
    DynamicFieldCreatorPtr argonFieldCreator_ = std::make_shared< DynamicFieldCreator >(
        argonField_, borderFieldCondition_, "LD Argon Field" );
    LDInterworkingPtr argontInterworking_ = std::make_shared< LDInterworking >();
    FieldReceiverPtr argonFieldResponsive_ = std::make_shared< FieldReceiver >(
        argonFieldCreator_, argontInterworking_, "LD Argon Feel" );
};

} // namespace phycoub
