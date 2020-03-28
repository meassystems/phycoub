/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 11:55:21
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 12:15:25
 */

#pragma once

#include <vector>
#include <memory>

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
#include "StdErrLogObserver.h"

namespace phycoub
{

class ElectronInHomogeneousFieldsCoub final : public PhyCoub
{
  public:
    ElectronInHomogeneousFieldsCoub();
    virtual ~ElectronInHomogeneousFieldsCoub() override = default;

    Vector getBorders() const;
    void setBorders( Vector borders );

    void addElectron(
        const Vector& coordinate, const Vector& speed, const ParticleOptions& options );

    void setElectricFieldDirection( Vector direction );
    Vector getElectricFieldDirection() const;
    void setElectricFieldCharge( double charge );
    double getElectricFieldCharge() const;

    void setMagneticFieldDirection( Vector direction );
    Vector getMagneticFieldDirection() const;
    void setMagneticFieldInduction( double B );
    double getMagneticFieldInduction() const;

    void setElectron2ElectronInterworkingFlag( bool flag );
    bool getElectron2ElectronInterworkingFlag() const;

  private:
    void initLog();
    void initCalculationGroup();
    void initElectricField();
    void initMagneticField();
    void initInterCommunication();
    void initWithElectronGroup();

    IDType electronGroupId_ = 0;

    CyclicBorderPtr cyclicBorder_;
    LeapFrogPtr leapFrog_;
    CalculationGroupPtr leapFrogCalculationGroup_;

    CulonInterworkingPtr culonInterworking_;
    ElectricHomogeneousDirectFieldPtr electricHomogeneousDirectField_;
    HomogeneousFieldCreatorPtr electricHomogeneousDirectFieldCreator_;
    FieldReceiverPtr feelElectricHomogeneousDirectWithCulonInterworking_;

    MagneticHomogeneousDirectFieldPtr magneticHomogeneousDirectField_;
    HomogeneousFieldCreatorPtr magneticHomogeneousDirectFieldCreator_;
    MagneticInterworkingPtr magneticInterworking_;
    FieldReceiverPtr feelWithMagneticInterworking_;

    bool electron2ElectronInterworkingFlag = false;
    BorderFieldConditionPtr borderFieldCondition_;
    ElectricFieldPtr electricField_;
    InterworkingPtr interworking_;
    InterCommunicationPtr electron2electronInterCommunication_;

    LogPtr stdErrLog;
    StdErrLogObserverPtr stdErrLogObserver;
};

using ElectronInHomogeneousFieldsCoubPtr
    = std::shared_ptr< ElectronInHomogeneousFieldsCoub >;

} // namespace phycoub