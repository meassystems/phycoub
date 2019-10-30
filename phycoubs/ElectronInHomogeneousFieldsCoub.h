/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 11:55:21
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-31 01:00:29
 */

#pragma once

#include <vector>

#include "PhyCoub.h"
#include "Vector.h"
#include "CyclicBorder.h"
#include "LeapFrog.h"
#include "ElectricHomogeneousField.h"
#include "MagneticHomogeneousField.h"
#include "Constants.h"
#include "CulonInterworking.h"
#include "MagneticInterworking.h"
#include "FieldCreator.h"
#include "FieldReceiver.h"
#include "HomogeneousFieldCreator.h"
#include "CalculationGroup.h"
#include "ElasticCoubCondition.h"

namespace phycoub
{

class ElectronInHomogeneousFieldsCoub final : public PhyCoub
{
  public:
    ElectronInHomogeneousFieldsCoub();
    ~ElectronInHomogeneousFieldsCoub() = default;

    const Vector& getBorders() const;
    const ParticleGroupList& getParticleGroupList();

    void addElectron( const Vector& coordinate, const Vector& speed );
    void removeParticle( long index );

    void setElectricFieldDirection( const Vector& direction );
    const Vector& getElectricFieldDirection() const;
    void setElectricFieldCharge( double charge );

    void setMagneticFieldDirection( const Vector& direction );
    const Vector& getMagneticFieldDirection() const;
    void setMagneticFieldInduction( double B );

  private:
    double dt_ = 1E-13;
    ParticleGroupPtr electrons_ = std::make_shared< ParticleGroup >();
    ParticleGroupList particleGroupList_;

    CyclicBorderPtr cyclicBorder_ = std::make_shared< CyclicBorder >( Vector{ 5.e-3 } );
    ElasticCoubConditionPtr elascticBorder_
        = std::make_shared< ElasticCoubCondition >( Vector{ 1.e-1 } );

    LeapFrogPtr leapFrog_ = std::make_shared< LeapFrog >();
    CalculationGroupPtr leapFrogCalculationGroup_
        = std::make_shared< CalculationGroup >( leapFrog_, cyclicBorder_ );

    ElectricHomogeneousFieldPtr electricHomogeneousField_
        = std::make_shared< ElectricHomogeneousField >(
            Vector{ 0, 0, 1 }, ElectricConstants::electronCharge * 0 );
    HomogeneousFieldCreatorPtr electricHomogeneousFieldCreator_
        = std::make_shared< HomogeneousFieldCreator >(
            electricHomogeneousField_, "ElectricHomogeneousField" );
    CulonInterworkingPtr culonInterworking_ = std::make_shared< CulonInterworking >();
    FieldReceiverPtr feelWithCulonInterworking_ = std::make_shared< FieldReceiver >(
        electricHomogeneousFieldCreator_, culonInterworking_, "culon interworking" );

    MagneticHomogeneousFieldPtr magneticHomogeneousField_
        = std::make_shared< MagneticHomogeneousField >( Vector{ 0, 1, 1 }, 1e-2 );
    HomogeneousFieldCreatorPtr magneticHomogeneousFieldCreator_
        = std::make_shared< HomogeneousFieldCreator >(
            magneticHomogeneousField_, "MagneticHomogeneousField" );
    MagneticInterworkingPtr magneticInterworking_
        = std::make_shared< MagneticInterworking >();
    FieldReceiverPtr feelWithMagneticInterworking_ = std::make_shared< FieldReceiver >(
        magneticHomogeneousFieldCreator_, magneticInterworking_, "culon interworking" );
};

} // namespace phycoub