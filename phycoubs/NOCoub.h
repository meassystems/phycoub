/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-19 19:07:25
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 08:55:45
 */

#pragma once

#include <vector>

#include "PhyCoub.h"
#include "Vector.h"
#include "ParticleGroup.h"
#include "CreateField.h"
#include "FeelField.h"
#include "CalculationGroup.h"
#include "ElasticCoubCondition.h"
#include "CyclicBorder.h"
#include "BorderFieldCondition.h"
#include "CyclicBoundedField.h"
#include "HighSpeedModificationVerle.h"
#include "LeapFrog.h"
#include "LDFieldFunction.h"
#include "LDInterworking.h"

namespace phycoub
{

class NOCoub final : public PhyCoub
{
  public:
    NOCoub();
    virtual ~NOCoub() = default;

    double dt_ = 1E-15, k_ = 1.38E-23, z_ = 0.;
    Vector borders_{ 1E-8, 1E-8, 1E-8 };
    double mN_ = 23.24E-27, epsN = 95.05 * k_, aN = 3.698E-10;
    double mO_ = 13.28E-27, epsO = 117.5 * k_, aO = 3.58E-10;
    double epsNO = 131. * k_, aNO = 3.17E-10;
    double radiusCatN_ = aN * 3;
    double radiusCatO_ = aO * 3;
    double radiusCatNO_ = aNO * 3;

    ParticleGroupPtr azot_ = std::make_shared< ParticleGroup >();
    ParticleGroupPtr oxygen_ = std::make_shared< ParticleGroup >();

  private:
    CyclicBorderPtr cyclicBorder_
        = std::make_shared< CyclicBorder >( CyclicBorder( borders_ ) );
    BorderFieldCondition borderFieldCondition_;

    CyclicBoundedField cyclicBoundedFieldN_{ CyclicBoundedField(
        &radiusCatN_, &borders_ ) };
    CyclicBoundedField cyclicBoundedFieldO_{ CyclicBoundedField(
        &radiusCatO_, &borders_ ) };
    CyclicBoundedField cyclicBoundedFieldNO_{ CyclicBoundedField(
        &radiusCatNO_, &borders_ ) };

    LeapFrog leapFrog_;
    CalculationGroupPtr leapFrogCalculationGroup_
        = std::make_shared< CalculationGroup >( &leapFrog_, cyclicBorder_ );

    LDFieldFunction azot2azotField_{ aN, aN, epsN };
    CreateFieldPtr azot2azotFieldCreator_ = std::make_shared< CreateField >(
        &azot2azotField_, &cyclicBoundedFieldN_, "LD NN Field" );
    LDInterworking azot2azotInterworking_;
    FeelFieldPtr azot2azotFieldResponsive_ = std::make_shared< FeelField >(
        azot2azotFieldCreator_, &azot2azotInterworking_, "LD NN Feel" );

    LDFieldFunction oxygenField_{ aO, aO, epsO };
    CreateFieldPtr oxygen2oxygenFieldCreator_ = std::make_shared< CreateField >(
        &oxygenField_, &cyclicBoundedFieldO_, "LD OO Field" );
    LDInterworking oxygenInterworking_;
    FeelFieldPtr oxygen2oxyhenFieldResponsive_ = std::make_shared< FeelField >(
        oxygen2oxygenFieldCreator_, &oxygenInterworking_, "LD OO Feel" );

    LDFieldFunction azot2oxygenField_{ aNO, aNO, epsO };
    CreateFieldPtr azot2oxygenFieldCreator_ = std::make_shared< CreateField >(
        &azot2oxygenField_, &cyclicBoundedFieldNO_, "LD NO Field" );
    LDInterworking azot2oxygenInterworking_;
    FeelFieldPtr azot2oxygenFieldResponsive_ = std::make_shared< FeelField >(
        azot2oxygenFieldCreator_, &azot2oxygenInterworking_, "LD NO Feel" );

    LDFieldFunction oxygen2azotField_{ aNO, aNO, epsO };
    CreateFieldPtr oxygen2azotFieldCreator_ = std::make_shared< CreateField >(
        &oxygen2azotField_, &cyclicBoundedFieldNO_, "LD ON Field" );
    LDInterworking oxygen2azotInterworking_;
    FeelFieldPtr oxygen2azotFieldResponsive_ = std::make_shared< FeelField >(
        oxygen2azotFieldCreator_, &oxygen2azotInterworking_, "LD ON Feel" );
};

} // namespace phycoub
