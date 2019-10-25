/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 11:55:21
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 23:21:27
 */

#pragma once

#include <vector>

#include "PhyCoub.h"
#include "Vector.h"
#include "CyclicBorder.h"
#include "LeapFrog.h"
#include "ElectricHomogeneousField.h"
#include "Constants.h"
#include "CulonInterworking.h"
#include "CreateFieldBase.h"
#include "FeelField.h"
#include "CreateHomogeneousField.h"
#include "CalculationGroup.h"

namespace phycoub
{

class ElectronInHomogeneousFieldsCoub final : public PhyCoub
{
  public:
    ElectronInHomogeneousFieldsCoub();
    ~ElectronInHomogeneousFieldsCoub() = default;

  private:
    double dt_ = 1E-15;
    Vector borders_{ 1.e-1 };
    CyclicBorderPtr cyclicBorder_ = std::make_shared< CyclicBorder >( &borders_ );

    LeapFrog leapFrog_;
    CalculationGroupPtr leapFrogCalculationGroup_
        = std::make_shared< CalculationGroup >( &leapFrog_, cyclicBorder_ );

    ElectricHomogeneousField electricHomogeneousField_{ { 0, 0, 1 },
        ElectricConstants::electronCharge * 10 };
    CreateHomogeneousFieldPtr electricHomogeneousFieldCreator_
        = std::make_shared< CreateHomogeneousField >(
            &electricHomogeneousField_, "ElectricHomogeneousField" );
    CulonInterworking culonInterworking_;
    FeelFieldPtr feelWithCulonInterworking_ = std::make_shared< FeelField >(
        electricHomogeneousFieldCreator_, &culonInterworking_, "culon interworking" );
};

} // namespace phycoub