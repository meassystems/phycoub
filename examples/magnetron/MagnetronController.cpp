#include "MagnetronController.h"

namespace phymagnetron
{

MagnetronController::MagnetronController()
    : magnetron_( std::make_shared< Magnetron >() )
    , phyCoubController_( std::make_shared< PhyCoubController >( magnetron_ ) )
    , gLRotationController_( std::make_shared< GLRotationController >() )
    , radiusScalarControllerAdapter_(
          std::make_shared< RadiusScalarControllerAdapter >( magnetron_ ) )
    , heightScalarControllerAdapter_(
          std::make_shared< HeightScalarControllerAdapter >( magnetron_ ) )
    , magneticScalarControllerAdapter_(
          std::make_shared< MagneticScalarControllerAdapter >( magnetron_ ) )
    , electricScalarControllerAdapter_(
          std::make_shared< ElectricScalarControllerAdapter >( magnetron_ ) )
    , energyScalarControllerAdapter_(
          std::make_shared< EnergyScalarControllerAdapter >( magnetron_ ) )
    , lifeParticleCountScalarControllerAdapter_(
          std::make_shared< LifeParticleCountScalarControllerAdapter >( magnetron_ ) )
{
}

// virtual override
Vector MagnetronController::getCoubSize() const
{
    return Vector{ magnetron_->getRadius() * 2, magnetron_->getRadius() * 2,
        magnetron_->getHeight() };
}

PhyCoubControllerWeakPtr MagnetronController::getPhyCoubController()
{
    return phyCoubController_;
}

GetParticlesAdapterWeakPtr MagnetronController::getGetParticleForGLAdapter()
{
    return phyCoubController_;
}

GLRotationControllerWeakPtr MagnetronController::getGLRotationController()
{
    return gLRotationController_;
}

DoubleControllerAdapterWeakPtr MagnetronController::getRadiusScalarControllerAdapter()
{
    return radiusScalarControllerAdapter_;
}

DoubleControllerAdapterWeakPtr MagnetronController::getHeightScalarControllerAdapter()
{
    return heightScalarControllerAdapter_;
}

DoubleControllerAdapterWeakPtr MagnetronController::getMagneticScalarControllerAdapter()
{
    return magneticScalarControllerAdapter_;
}

DoubleControllerAdapterWeakPtr MagnetronController::getElectricScalarControllerAdapter()
{
    return electricScalarControllerAdapter_;
}

DoubleControllerAdapterWeakPtr MagnetronController::getEnergyScalarControllerAdapter()
{
    return energyScalarControllerAdapter_;
}

LongControllerAdapterWeakPtr
MagnetronController::getLifeParticleCountScalarControllerAdapter()
{
    return lifeParticleCountScalarControllerAdapter_;
}

} // namespace phymagnetron
