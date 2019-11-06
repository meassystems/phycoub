/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 11:55:21
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-06 01:44:01
 */

#pragma once

#include <vector>

#include "PhyCoub.h"
#include "ContainParticleGroupList.h"
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
#include "BorderFieldCondition.h"
#include "ElectricField.h"
#include "CulonInterworking.h"
#include "InterCommunication.h"

namespace phycoub
{

class ElectronInHomogeneousFieldsCoub final
    : public PhyCoub
    , public ContainParticleGroupList
{
  public:
    ElectronInHomogeneousFieldsCoub();
    ~ElectronInHomogeneousFieldsCoub() = default;

    const Vector& getBorders() const;
    void setBorders( const Vector& borders );

    const ParticleGroupList& getParticleGroupList();

    void addElectron( const Vector& coordinate, const Vector& speed );
    void removeParticle( long index );

    void setElectricFieldDirection( const Vector& direction );
    const Vector& getElectricFieldDirection() const;
    void setElectricFieldCharge( double charge );
    double getElectricFieldCharge() const;

    void setMagneticFieldDirection( const Vector& direction );
    const Vector& getMagneticFieldDirection() const;
    void setMagneticFieldInduction( double B );
    double getMagneticFieldInduction() const;

    void switchElectron2ElectronInterworking( bool flag );

  private:
    ParticleGroupPtr electrons_ = std::make_shared< ParticleGroup >();

    CyclicBorderPtr cyclicBorder_ = std::make_shared< CyclicBorder >( Vector{ 1.e-4 } );

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
        = std::make_shared< MagneticHomogeneousField >( Vector{ 0, 1, 1 }, 3e-2 );
    HomogeneousFieldCreatorPtr magneticHomogeneousFieldCreator_
        = std::make_shared< HomogeneousFieldCreator >(
            magneticHomogeneousField_, "MagneticHomogeneousField" );
    MagneticInterworkingPtr magneticInterworking_
        = std::make_shared< MagneticInterworking >();
    FieldReceiverPtr feelWithMagneticInterworking_ = std::make_shared< FieldReceiver >(
        magneticHomogeneousFieldCreator_, magneticInterworking_, "culon interworking" );

    BorderFieldConditionPtr borderFieldCondition_
        = std::make_shared< BorderFieldCondition >();
    ElectricFieldPtr electricField_ = std::make_shared< ElectricField >();
    InterworkingPtr interworking_ = std::make_shared< CulonInterworking >();
    InterCommunicationPtr electron2electronInterCommunication_
        = std::make_shared< InterCommunication >( electricField_, borderFieldCondition_,
            interworking_, "electron-electron InterCommunication" );
};

} // namespace phycoub