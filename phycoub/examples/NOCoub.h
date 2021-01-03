/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-19 19:07:25
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 13:53:48
 */

#pragma once

#include <vector>

#include "PhyCoub.h"
#include "Vector.h"
#include "ParticleGroup.h"
#include "DynamicFieldCreator.h"
#include "FieldReceiver.h"
#include "CalculationGroup.h"
#include "ElasticCoubCondition.h"
#include "CyclicBorder.h"
#include "BorderFieldCondition.h"
#include "CyclicBoundedField.h"
#include "HighSpeedModificationVerle.h"
#include "LeapFrog.h"
#include "LDField.h"
#include "LDInterworking.h"
#include "InterGroupCommunication.h"

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

  private:
    CyclicBorderPtr cyclicBorder_
        = std::make_shared< CyclicBorder >( CyclicBorder( borders_ ) );
    BorderFieldCondition borderFieldCondition_;

    CyclicBoundedFieldPtr cyclicBoundedFieldN_
        = std::make_shared< CyclicBoundedField >( borders_, radiusCatN_ );
    CyclicBoundedFieldPtr cyclicBoundedFieldO_
        = std::make_shared< CyclicBoundedField >( borders_, radiusCatO_ );
    CyclicBoundedFieldPtr cyclicBoundedFieldNO_
        = std::make_shared< CyclicBoundedField >( borders_, radiusCatNO_ );

    LeapFrogPtr leapFrog_ = std::make_shared< LeapFrog >();
    CalculationGroupPtr leapFrogCalculationGroup_
        = std::make_shared< CalculationGroup >( leapFrog_, cyclicBorder_ );

    LDInterworkingPtr interworkingFunction = std::make_shared< LDInterworking >();

    LDFieldPtr azot2azotField_ = std::make_shared< LDField >( aN, aN, epsN );
    DynamicFieldCreatorPtr azot2azotFieldCreator_
        = std::make_shared< DynamicFieldCreator >(
            azot2azotField_, cyclicBoundedFieldN_, "LD NN Field" );
    FieldReceiverPtr azot2azotFieldResponsive_ = std::make_shared< FieldReceiver >(
        azot2azotFieldCreator_, interworkingFunction, "LD NN Feel" );

    LDFieldPtr oxygenField_ = std::make_shared< LDField >( aO, aO, epsO );
    DynamicFieldCreatorPtr oxygen2oxygenFieldCreator_
        = std::make_shared< DynamicFieldCreator >(
            oxygenField_, cyclicBoundedFieldO_, "LD OO Field" );
    FieldReceiverPtr oxygen2oxyhenFieldResponsive_ = std::make_shared< FieldReceiver >(
        oxygen2oxygenFieldCreator_, interworkingFunction, "LD OO Feel" );

    LDFieldPtr azot2oxygenField_ = std::make_shared< LDField >( aNO, aNO, epsO );
    InterGroupCommunicationPtr azot2oxygenInterCommunication_
        = std::make_shared< InterGroupCommunication >( azot2oxygenField_,
            cyclicBoundedFieldNO_, interworkingFunction, "LD NO InterCommunication" );
};

} // namespace phycoub
