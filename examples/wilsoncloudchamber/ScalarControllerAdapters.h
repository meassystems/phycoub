#ifndef SCALARCONTROLLERADAPTERS_H
#define SCALARCONTROLLERADAPTERS_H

#include <memory>

#include "ValueControllerAdapterIface.h"
#include "WilsonCloudChamber.h"

namespace phywilsoncloudchamber
{

using namespace phycoub;
using namespace phywidgets;

using SizeScalarControllerAdapter = ValueControllerAdapter< Vector, WilsonCloudChamber,
    &WilsonCloudChamber::getBorders, &WilsonCloudChamber::setBorders >;
using SizeScalarControllerAdapterPtr = std::shared_ptr< SizeScalarControllerAdapter >;

using MagneticDirectionScalarControllerAdapter = ValueControllerAdapter< Vector,
    WilsonCloudChamber, &WilsonCloudChamber::getMagneticFieldDirection,
    &WilsonCloudChamber::setMagneticFieldDirection >;
using MagneticDirectionScalarControllerAdapterPtr
    = std::shared_ptr< MagneticDirectionScalarControllerAdapter >;

using MagneticScalarControllerAdapter = ValueControllerAdapter< double,
    WilsonCloudChamber, &WilsonCloudChamber::getMagneticFieldInduction,
    &WilsonCloudChamber::setMagneticFieldInduction >;
using MagneticScalarControllerAdapterPtr
    = std::shared_ptr< MagneticScalarControllerAdapter >;

using ElectricDirectionScalarControllerAdapter = ValueControllerAdapter< Vector,
    WilsonCloudChamber, &WilsonCloudChamber::getElectricFieldDirection,
    &WilsonCloudChamber::setElectricFieldDirection >;
using ElectricDirectionScalarControllerAdapterPtr
    = std::shared_ptr< ElectricDirectionScalarControllerAdapter >;

using ElectricScalarControllerAdapter = ValueControllerAdapter< double,
    WilsonCloudChamber, &WilsonCloudChamber::getElectricFieldCharge,
    &WilsonCloudChamber::setElectricFieldCharge >;
using ElectricScalarControllerAdapterPtr
    = std::shared_ptr< ElectricScalarControllerAdapter >;

using ElectronSourceDirectionScalarControllerAdapter = ValueControllerAdapter< Vector,
    WilsonCloudChamber, &WilsonCloudChamber::getElectronSourceDirection,
    &WilsonCloudChamber::setElectronSourceDirection >;
using ElectronSourceDirectionScalarControllerAdapterPtr
    = std::shared_ptr< ElectronSourceDirectionScalarControllerAdapter >;

using ElectronSourceAngleControllerAdapter = ValueControllerAdapter< double,
    WilsonCloudChamber, &WilsonCloudChamber::getElectronSourceAngle,
    &WilsonCloudChamber::setElectronSourceAngel >;
using ElectronSourceAngleControllerAdapterPtr
    = std::shared_ptr< ElectronSourceAngleControllerAdapter >;

using ElectronSourceBornPeriodControllerAdapter = ValueControllerAdapter< double,
    WilsonCloudChamber, &WilsonCloudChamber::getElectronSourceBornPeriod,
    &WilsonCloudChamber::setElectronSourcBornPeriod >;
using ElectronSourceBornPeriodControllerAdapterPtr
    = std::shared_ptr< ElectronSourceBornPeriodControllerAdapter >;

using ElectronSourceBornEnergyControllerAdapter = ValueControllerAdapter< double,
    WilsonCloudChamber, &WilsonCloudChamber::getElectronSourceBornEnergy,
    &WilsonCloudChamber::setElectronSourceBornEnergy >;
using ElectronSourceBornEnergyControllerAdapterPtr
    = std::shared_ptr< ElectronSourceBornEnergyControllerAdapter >;

using ProtonSourceDirectionScalarControllerAdapter = ValueControllerAdapter< Vector,
    WilsonCloudChamber, &WilsonCloudChamber::getProtonSourceDirection,
    &WilsonCloudChamber::setProtonSourceDirection >;
using ProtonSourceDirectionScalarControllerAdapterPtr
    = std::shared_ptr< ProtonSourceDirectionScalarControllerAdapter >;

using ProtonSourceAngleControllerAdapter = ValueControllerAdapter< double,
    WilsonCloudChamber, &WilsonCloudChamber::getProtonSourceAngle,
    &WilsonCloudChamber::setProtonSourceAngel >;
using ProtonSourceAngleControllerAdapterPtr
    = std::shared_ptr< ProtonSourceAngleControllerAdapter >;

using ProtonSourceBornPeriodControllerAdapter = ValueControllerAdapter< double,
    WilsonCloudChamber, &WilsonCloudChamber::getProtonSourceBornPeriod,
    &WilsonCloudChamber::setProtonSourcBornPeriod >;
using ProtonSourceBornPeriodControllerAdapterPtr
    = std::shared_ptr< ProtonSourceBornPeriodControllerAdapter >;

using ProtonSourceBornEnergyControllerAdapter = ValueControllerAdapter< double,
    WilsonCloudChamber, &WilsonCloudChamber::getProtonSourceBornEnergy,
    &WilsonCloudChamber::setProtonSourceBornEnergy >;
using ProtonSourceBornEnergyControllerAdapterPtr
    = std::shared_ptr< ProtonSourceBornEnergyControllerAdapter >;

using SpecificSourceDirectionScalarControllerAdapter = ValueControllerAdapter< Vector,
    WilsonCloudChamber, &WilsonCloudChamber::getSpecificSourceDirection,
    &WilsonCloudChamber::setSpecificSourceDirection >;
using SpecificSourceDirectionScalarControllerAdapterPtr
    = std::shared_ptr< SpecificSourceDirectionScalarControllerAdapter >;

using SpecificSourceAngleControllerAdapter = ValueControllerAdapter< double,
    WilsonCloudChamber, &WilsonCloudChamber::getSpecificSourceAngle,
    &WilsonCloudChamber::setSpecificSourceAngel >;
using SpecificSourceAngleControllerAdapterPtr
    = std::shared_ptr< SpecificSourceAngleControllerAdapter >;

using SpecificSourceBornPeriodControllerAdapter = ValueControllerAdapter< double,
    WilsonCloudChamber, &WilsonCloudChamber::getSpecificSourceBornPeriod,
    &WilsonCloudChamber::setSpecificSourcBornPeriod >;
using SpecificSourceBornPeriodControllerAdapterPtr
    = std::shared_ptr< SpecificSourceBornPeriodControllerAdapter >;

using SpecificSourceBornEnergyControllerAdapter = ValueControllerAdapter< double,
    WilsonCloudChamber, &WilsonCloudChamber::getSpecificSourceBornEnergy,
    &WilsonCloudChamber::setSpecificSourceBornEnergy >;
using SpecificSourceBornEnergyControllerAdapterPtr
    = std::shared_ptr< SpecificSourceBornEnergyControllerAdapter >;

using SpecificSourceParticleOptionsControllerAdapter
    = ValueControllerAdapter< ParticleOptions, WilsonCloudChamber,
        &WilsonCloudChamber::getSpecificSourceParticleOptions,
        &WilsonCloudChamber::setSpecificSourceParticleOptions >;
using SpecificSourceParticleOptionsControllerAdapterPtr
    = std::shared_ptr< SpecificSourceParticleOptionsControllerAdapter >;

} // namespace phywilsoncloudchamber

#endif // SCALARCONTROLLERADAPTERS_H
