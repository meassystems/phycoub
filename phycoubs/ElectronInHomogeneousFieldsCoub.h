/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 11:55:21
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-10 15:36:09
 */

#pragma once

#include <vector>

#include "PhyCoub.h"
#include "Vector.h"
#include "CyclicBorder.h"
#include "LeapFrog.h"
#include "ElectricHomogeneousRadialXYField.h"
#include "ElectricHomogeneousDirectField.h"
#include "MagneticHomogeneousDirectField.h"
#include "Constants.h"
#include "CulonInterworking.h"
#include "MagneticInterworking.h"
#include "FieldCreator.h"
#include "FieldReceiver.h"
#include "HomogeneousFieldCreator.h"
#include "CalculationGroup.h"
#include "ElasticCoubCondition.h"
#include "BorderFieldCondition.h"
#include "ElectricField.h"
#include "CulonInterworking.h"
#include "InterCommunication.h"

namespace phycoub
{

class ElectronInHomogeneousFieldsCoub final : public PhyCoub
{
  public:
    ElectronInHomogeneousFieldsCoub();
    ~ElectronInHomogeneousFieldsCoub() = default;

    const Vector& getBorders() const;
    void setBorders( const Vector& borders );

    void addElectron( const Vector& coordinate, const Vector& speed );
    void removeParticle( long index );

    void setElectricRadialCenter( const Vector& center );
    const Vector& getElectricRadialCenter() const;
    void setElectricRadialRadius( double radius );
    double getElectricRadialRadius() const;
    void setElectricRadialFieldCharge( double charge );
    double getElectricRadialFieldCharge() const;

    void setElectricFieldDirection( const Vector& direction );
    Vector getElectricFieldDirection() const;
    void setElectricFieldCharge( double charge );
    double getElectricFieldCharge() const;

    void setMagneticFieldDirection( const Vector& direction );
    Vector getMagneticFieldDirection() const;
    void setMagneticFieldInduction( double B );
    double getMagneticFieldInduction() const;

    void switchElectron2ElectronInterworking( bool flag );

  private:
    ParticleGroupPtr electrons_ = std::make_shared< ParticleGroup >();

    constexpr static double borderSize_ = 1.e-4;
    CyclicBorderPtr cyclicBorder_
        = std::make_shared< CyclicBorder >( Vector{ borderSize_ } );

    LeapFrogPtr leapFrog_ = std::make_shared< LeapFrog >();
    CalculationGroupPtr leapFrogCalculationGroup_
        = std::make_shared< CalculationGroup >( leapFrog_, cyclicBorder_ );

    CulonInterworkingPtr culonInterworking_ = std::make_shared< CulonInterworking >();

    ElectricHomogeneousRadialXYFieldPtr electricHomogeneousRadialField_
        = std::make_shared< ElectricHomogeneousRadialXYField >(
            Vector{ borderSize_ * 0.5 }, borderSize_ * 0.8,
            ElectricConstants::electronCharge * 1e9 );
    HomogeneousFieldCreatorPtr electricHomogeneousRadialFieldCreator_
        = std::make_shared< HomogeneousFieldCreator >(
            electricHomogeneousRadialField_, "ElectricHomogeneousRadialField" );
    FieldReceiverPtr feelElectricHomogeneousRadialWithCulonInterworking_
        = std::make_shared< FieldReceiver >( electricHomogeneousRadialFieldCreator_,
            culonInterworking_, "ElectricHomogeneousRadialField culon interworking" );

    ElectricHomogeneousDirectFieldPtr electricHomogeneousDirectField_
        = std::make_shared< ElectricHomogeneousDirectField >(
            Vector{ 0, 0, 1 }, ElectricConstants::electronCharge * 0 );
    HomogeneousFieldCreatorPtr electricHomogeneousDirectFieldCreator_
        = std::make_shared< HomogeneousFieldCreator >(
            electricHomogeneousDirectField_, "ElectricHomogeneousField" );
    FieldReceiverPtr feelElectricHomogeneousDirectWithCulonInterworking_
        = std::make_shared< FieldReceiver >( electricHomogeneousDirectFieldCreator_,
            culonInterworking_, "culon interworking" );

    MagneticHomogeneousDirectFieldPtr magneticHomogeneousDirectField_
        = std::make_shared< MagneticHomogeneousDirectField >( Vector{ 0, 1, 1 }, 3e-2 );
    HomogeneousFieldCreatorPtr magneticHomogeneousDirectFieldCreator_
        = std::make_shared< HomogeneousFieldCreator >(
            magneticHomogeneousDirectField_, "MagneticHomogeneousField" );
    MagneticInterworkingPtr magneticInterworking_
        = std::make_shared< MagneticInterworking >();
    FieldReceiverPtr feelWithMagneticInterworking_
        = std::make_shared< FieldReceiver >( magneticHomogeneousDirectFieldCreator_,
            magneticInterworking_, "magnetic interworking" );

    BorderFieldConditionPtr borderFieldCondition_
        = std::make_shared< BorderFieldCondition >();
    ElectricFieldPtr electricField_ = std::make_shared< ElectricField >();
    InterworkingPtr interworking_ = std::make_shared< CulonInterworking >();
    InterCommunicationPtr electron2electronInterCommunication_
        = std::make_shared< InterCommunication >( electricField_, borderFieldCondition_,
            interworking_, "electron-electron InterCommunication" );
};

} // namespace phycoub