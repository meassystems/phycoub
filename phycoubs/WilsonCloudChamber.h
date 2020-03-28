/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-16 01:12:25
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-28 22:38:17
 */

#pragma once

#include "PhyCoub.h"
#include "CyclicBorder.h"
#include "LeapFrog.h"
#include "CulonInterworking.h"
#include "MagneticInterworking.h"
#include "Constants.h"
#include "ElectricField.h"
#include "ElectricHomogeneousDirectField.h"
#include "MagneticHomogeneousDirectField.h"
#include "HomogeneousFieldCreator.h"
#include "FieldReceiver.h"
#include "BorderFieldCondition.h"
#include "InterCommunication.h"
#include "InterGroupCommunication.h"
#include "ConeParticleSource.h"
#include "BornPeriodLifeTimeController.h"
#include "StdErrLogObserver.h"

namespace phycoub
{

class WilsonCloudChamber : public PhyCoub
{
  public:
    WilsonCloudChamber();
    virtual ~WilsonCloudChamber() override = default;

    Vector getBorders() const;
    void setBorders( Vector borders );

    void setElectricFieldDirection( Vector direction );
    Vector getElectricFieldDirection() const;
    void setElectricFieldCharge( double charge );
    double getElectricFieldCharge() const;

    void setMagneticFieldDirection( Vector direction );
    Vector getMagneticFieldDirection() const;
    void setMagneticFieldInduction( double B );
    double getMagneticFieldInduction() const;

    void setElectronSourceDirection( Vector direction );
    Vector getElectronSourceDirection() const;
    void setElectronSourceAngel( double angle );
    double getElectronSourceAngle() const;
    void setElectronSourcBornPeriod( double bornPeriod );
    double getElectronSourceBornPeriod() const;

    void setProtonSourceDirection( Vector direction );
    Vector getProtonSourceDirection() const;
    void setProtonSourceAngel( double angle );
    double getProtonSourceAngle() const;
    void setProtonSourcBornPeriod( double bornPeriod );
    double getProtonSourceBornPeriod() const;

    void setSpecificSourceDirection( Vector direction );
    Vector getSpecificSourceDirection() const;
    void setSpecificSourceAngel( double angle );
    double getSpecificSourceAngle() const;
    void setSpecificSourcBornPeriod( double bornPeriod );
    double getSpecificSourceBornPeriod() const;

    void setSpecificSourceParticleOptions( ParticleOptions options );
    ParticleOptions getSpecificSourceParticleOptions() const;

  private:
    void initLog();
    void initCalculationGroup();
    void initElectricField();
    void initMagneticField();
    void initInterCommunication();
    void initSourcesAndLifeTimeControllers();
    void initWithParticleGroups();

    CyclicBorderPtr cyclicBorder_;
    LeapFrogPtr leapFrog_;
    CalculationGroupPtr leapFrogCalculationGroup_;

    CulonInterworkingPtr culonInterworking_;
    ElectricHomogeneousDirectFieldPtr electricHomogeneousDirectField_;
    HomogeneousFieldCreatorPtr electricHomogeneousDirectFieldCreator_;
    FieldReceiverPtr feelElectricHomogeneousDirectWithCulonInterworking_;

    MagneticInterworkingPtr magneticInterworking_;
    MagneticHomogeneousDirectFieldPtr magneticHomogeneousDirectField_;
    HomogeneousFieldCreatorPtr magneticHomogeneousDirectFieldCreator_;
    FieldReceiverPtr feelWithMagneticInterworking_;

    InterworkingPtr interworking_;
    BorderFieldConditionPtr borderFieldCondition_;
    ElectricFieldPtr electricField_;

    /*
        Можно было бы обойтись одной группой, но с целью тестирования
        частицы разделенеы на три группы
    */
    InterCommunicationPtr electronInterCommunication_;
    InterCommunicationPtr protonInterCommunication_;
    InterCommunicationPtr specificInterCommunication_;
    InterGroupCommunicationPtr groupInterCommunication_;

    ConeParticleSourcePtr electronConeParticleSource_;
    BornPeriodLifeTimeControllerPtr electronBornPeriodLifeTimeController_;

    ConeParticleSourcePtr protonConeParticleSource_;
    BornPeriodLifeTimeControllerPtr protonBornPeriodLifeTimeController_;

    ConeParticleSourcePtr specificConeParticleSource_;
    BornPeriodLifeTimeControllerPtr specificBornPeriodLifeTimeController_;

    LogPtr stdErrLog;
    StdErrLogObserverPtr stdErrLogObserver;
};

} // namespace phycoub