/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-06 22:12:25
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 12:46:03
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
    virtual ~Magnetron() override = default;

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
    void initLog();
    void initCalculationGroup();
    void initElectricField();
    void initMagneticField();
    void initInterCommunication();
    void initElectronSource();
    void initWithElectronGroup();

    CylinderBorderConditionPtr cylinderBorderCondition_;
    LeapFrogPtr leapFrog_;
    CalculationGroupPtr leapFrogCalculationGroup_;

    ElectricHomogeneousRadialXYFieldPtr electricHomogeneousRadialField_;
    HomogeneousFieldCreatorPtr electricHomogeneousRadialFieldCreator_;
    CulonInterworkingPtr culonInterworking_;
    FieldReceiverPtr feelElectricHomogeneousRadialWithCulonInterworking_;

    MagneticHomogeneousDirectFieldPtr magneticHomogeneousDirectField_;
    HomogeneousFieldCreatorPtr magneticHomogeneousDirectFieldCreator_;
    MagneticInterworkingPtr magneticInterworking_;
    FieldReceiverPtr feelWithMagneticInterworking_;

    BorderFieldConditionPtr borderFieldCondition_;
    ElectricFieldPtr electricField_;
    InterworkingPtr interworking_;
    InterCommunicationPtr electron2electronInterCommunication_;

    CylindricalXYPartcleSourcePtr cylindricalXYPartcleSource_;
    QuantityLifeTimeControllerPtr quantityLifeTimeController_;

    LogPtr stdErrLog;
    StdErrLogObserverPtr stdErrLogObserver;
};

using MagnetronPtr = std::shared_ptr< Magnetron >;

} // namespace phycoub