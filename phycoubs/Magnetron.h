/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-06 22:12:25
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-14 11:50:30
 */

#pragma once

#include <memory>

#include "PhyCoub.h"
#include "CylinderBorderCondition.h"
#include "LeapFrog.h"
#include "CulonInterworking.h"
#include "MagneticInterworking.h"
#include "Constants.h"
#include "ElectricHomogeneousRadialXYField.h"
#include "MagneticHomogeneousDirectField.h"
#include "HomogeneousFieldCreator.h"
#include "FieldReceiver.h"
#include "BorderFieldCondition.h"
#include "ElectricField.h"
#include "InterCommunication.h"
#include "CylindricalXYParticleSource.h"
#include "QuantityLifeTimeController.h"
#include "StdErrLogObserver.h"

namespace phycoub
{

class Magnetron final : public PhyCoub
{
  public:
    Magnetron();
    ~Magnetron() = default;

    double getRadius() const;
    void setRadius( double radius );

    double getHeight() const;
    void setHeigtht( double height );

    double getElectricRadialFieldCharge() const;
    void setElectricRadialFieldCharge( double charge );

    double getMagneticFieldInduction() const;
    void setMagneticFieldInduction( double B );

    double getEnergy() const;
    void setEnergy( double energy );

    long getLifeParticleCount() const;
    void setLifeParticleCount( long count );

  private:
    CylinderBorderConditionPtr cylinderBorderCondition_
        = std::make_shared< CylinderBorderCondition >( 1., 1. );

    LeapFrogPtr leapFrog_ = std::make_shared< LeapFrog >();
    CalculationGroupPtr leapFrogCalculationGroup_
        = std::make_shared< CalculationGroup >( leapFrog_, cylinderBorderCondition_ );

    ElectricHomogeneousRadialXYFieldPtr electricHomogeneousRadialField_
        = std::make_shared< ElectricHomogeneousRadialXYField >(
            Vector{ 1., 1., 0 }, 1., ElectricConstants::electronCharge * 1e16 );
    HomogeneousFieldCreatorPtr electricHomogeneousRadialFieldCreator_
        = std::make_shared< HomogeneousFieldCreator >(
            electricHomogeneousRadialField_, "ElectricHomogeneousRadialField" );
    CulonInterworkingPtr culonInterworking_ = std::make_shared< CulonInterworking >();
    FieldReceiverPtr feelElectricHomogeneousRadialWithCulonInterworking_
        = std::make_shared< FieldReceiver >( electricHomogeneousRadialFieldCreator_,
            culonInterworking_, "ElectricHomogeneousRadialField culon interworking" );

    MagneticHomogeneousDirectFieldPtr magneticHomogeneousDirectField_
        = std::make_shared< MagneticHomogeneousDirectField >(
            Vector{ 0., 0., 1. }, 3e-2 );
    HomogeneousFieldCreatorPtr magneticHomogeneousDirectFieldCreator_
        = std::make_shared< HomogeneousFieldCreator >(
            magneticHomogeneousDirectField_, "MagneticHomogeneousField" );
    MagneticInterworkingPtr magneticInterworking_
        = std::make_shared< MagneticInterworking >();
    FieldReceiverPtr feelWithMagneticInterworking_
        = std::make_shared< FieldReceiver >( magneticHomogeneousDirectFieldCreator_,
            magneticInterworking_, "Magnetic interworking" );

    BorderFieldConditionPtr borderFieldCondition_
        = std::make_shared< BorderFieldCondition >();
    ElectricFieldPtr electricField_ = std::make_shared< ElectricField >();
    InterworkingPtr interworking_ = std::make_shared< CulonInterworking >();
    InterCommunicationPtr electron2electronInterCommunication_
        = std::make_shared< InterCommunication >( electricField_, borderFieldCondition_,
            interworking_, "electron-electron InterCommunication" );

    CylindricalXYPartcleSourcePtr cylindricalXYPartcleSource_;
    QuantityLifeTimeControllerPtr quantityLifeTimeController_;

    StdErrLogObserverPtr stdErrLogObserver = std::make_shared< StdErrLogObserver >();
};

using MagnetronPtr = std::shared_ptr< Magnetron >;

} // namespace phycoub