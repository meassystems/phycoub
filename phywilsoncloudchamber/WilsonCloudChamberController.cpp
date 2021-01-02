#include "WilsonCloudChamberController.h"

namespace phywilsoncloudchamber
{

WilsonCloudChamberController::WilsonCloudChamberController()
    : coub_( std::make_shared< WilsonCloudChamber >() )
    , phyCoubController_( std::make_shared< PhyCoubController >( coub_ ) )
    , gLRotationController_( std::make_shared< GLRotationController >() )
    , sizeScalarControlAdapter_(
          std::make_shared< SizeScalarControllerAdapter >( coub_ ) )
    , magneticDirectionScalarControllerAdapter_(
          std::make_shared< MagneticDirectionScalarControllerAdapter >( coub_ ) )
    , magneticScalarControllerAdapter_(
          std::make_shared< MagneticScalarControllerAdapter >( coub_ ) )
    , electricDirectionScalarControllerAdapter_(
          std::make_shared< ElectricDirectionScalarControllerAdapter >( coub_ ) )
    , electricScalaraControllerAdapter_(
          std::make_shared< ElectricScalarControllerAdapter >( coub_ ) )
    , electronSourceDirectionScalarControllerAdapter_(
          std::make_shared< ElectronSourceDirectionScalarControllerAdapter >( coub_ ) )
    , electronSourceAngleControllerAdapter_(
          std::make_shared< ElectronSourceAngleControllerAdapter >( coub_ ) )
    , electronSourceBornPeriodControllerAdapter_(
          std::make_shared< ElectronSourceBornPeriodControllerAdapter >( coub_ ) )
    , electronSourceBornEnergyControllerAdapter_(
          std::make_shared< ElectronSourceBornEnergyControllerAdapter >( coub_ ) )
    , protonSourceDirectionScalarControllerAdapter_(
          std::make_shared< ProtonSourceDirectionScalarControllerAdapter >( coub_ ) )
    , protonSourceAngleControllerAdapter_(
          std::make_shared< ProtonSourceAngleControllerAdapter >( coub_ ) )
    , protonSourceBornPeriodControllerAdapter_(
          std::make_shared< ProtonSourceBornPeriodControllerAdapter >( coub_ ) )
    , protonSourceBornEnergyControllerAdapter_(
          std::make_shared< ProtonSourceBornEnergyControllerAdapter >( coub_ ) )
    , specificSourceDirectionScalarControllerAdapter_(
          std::make_shared< SpecificSourceDirectionScalarControllerAdapter >( coub_ ) )
    , specificSourceAngleControllerAdapter_(
          std::make_shared< SpecificSourceAngleControllerAdapter >( coub_ ) )
    , specificSourceBornPeriodControllerAdapter_(
          std::make_shared< SpecificSourceBornPeriodControllerAdapter >( coub_ ) )
    , specificSourceBornEnergyControllerAdapter_(
          std::make_shared< SpecificSourceBornEnergyControllerAdapter >( coub_ ) )
    , specificSourceParticleOptionsControllerAdapter_(
          std::make_shared< SpecificSourceParticleOptionsControllerAdapter >( coub_ ) )

{
}

// virtual override
Vector WilsonCloudChamberController::getCoubSize() const
{
    return coub_->getBorders();
}

PhyCoubControllerWeakPtr WilsonCloudChamberController::getPhyCoubController()
{
    return phyCoubController_;
}

GetParticlesAdapterWeakPtr WilsonCloudChamberController::getGetParticleForGLAdapter()
{
    return phyCoubController_;
}

GLRotationControllerWeakPtr WilsonCloudChamberController::getGLRotationController()
{
    return gLRotationController_;
}

VectorControllerAdapterWeakPtr
WilsonCloudChamberController::getSizeScalarControllerAdapter()
{
    return sizeScalarControlAdapter_;
}

VectorControllerAdapterWeakPtr
WilsonCloudChamberController::getMagneticDirectionControllerAdapter()
{
    return magneticDirectionScalarControllerAdapter_;
}

DoubleControllerAdapterWeakPtr
WilsonCloudChamberController::getMagneticScalarControllerAdapter()
{
    return magneticScalarControllerAdapter_;
}

VectorControllerAdapterWeakPtr
WilsonCloudChamberController::getElectricDirectionControllerAdapter()
{
    return electricDirectionScalarControllerAdapter_;
}

DoubleControllerAdapterWeakPtr
WilsonCloudChamberController::getElectricScalarControllerAdapter()
{
    return electricScalaraControllerAdapter_;
}

VectorControllerAdapterWeakPtr
WilsonCloudChamberController::getElectronSourceDirectionScalarControllerAdapter()
{
    return electronSourceDirectionScalarControllerAdapter_;
}

DoubleControllerAdapterWeakPtr
WilsonCloudChamberController::getElectronSourceAngleControllerAdapter()
{
    return electronSourceAngleControllerAdapter_;
}

DoubleControllerAdapterWeakPtr
WilsonCloudChamberController::getElectronSourceBornPeriodControllerAdapter()
{
    return electronSourceBornPeriodControllerAdapter_;
}

DoubleControllerAdapterWeakPtr
WilsonCloudChamberController::getElectronSourceBornEnergyControllerAdapter()
{
    return electronSourceBornEnergyControllerAdapter_;
}

VectorControllerAdapterWeakPtr
WilsonCloudChamberController::getProtonSourceDirectionScalarControllerAdapter()
{
    return protonSourceDirectionScalarControllerAdapter_;
}

DoubleControllerAdapterWeakPtr
WilsonCloudChamberController::getProtonSourceAngleControllerAdapter()
{
    return protonSourceAngleControllerAdapter_;
}

DoubleControllerAdapterWeakPtr
WilsonCloudChamberController::getProtonSourceBornPeriodControllerAdapter()
{
    return protonSourceBornPeriodControllerAdapter_;
}

DoubleControllerAdapterWeakPtr
WilsonCloudChamberController::getProtonSourceBornEnergyControllerAdapter()
{
    return protonSourceBornEnergyControllerAdapter_;
}

VectorControllerAdapterWeakPtr
WilsonCloudChamberController::getSpecificSourceDirectionScalarControllerAdapter()
{
    return specificSourceDirectionScalarControllerAdapter_;
}

DoubleControllerAdapterWeakPtr
WilsonCloudChamberController::getSpecificSourceAngleControllerAdapter()
{
    return specificSourceAngleControllerAdapter_;
}

DoubleControllerAdapterWeakPtr
WilsonCloudChamberController::getSpecificSourceBornPeriodControllerAdapter()
{
    return specificSourceBornPeriodControllerAdapter_;
}

DoubleControllerAdapterWeakPtr
WilsonCloudChamberController::getSpecificSourceBornEnergyControllerAdapter()
{
    return specificSourceBornEnergyControllerAdapter_;
}

ParticleOptionsControllerAdapterWeakPtr
WilsonCloudChamberController::getSpecificSourceParticleOptionsControllerAdapter()
{
    return specificSourceParticleOptionsControllerAdapter_;
}

} // namespace phywilsoncloudchamber
