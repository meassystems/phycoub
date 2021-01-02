#include "ElectronInHomogeneousFieldsController.h"

namespace phyelectroninhomogeneousfields
{

ElectronInHomogeneousFieldsController::ElectronInHomogeneousFieldsController()
    : coub_( std::make_shared< ElectronInHomogeneousFieldsCoub >() )
    , phyCoubController_( std::make_shared< PhyCoubController >( coub_ ) )
    , gLRotationController_( std::make_shared< GLRotationController >() )
    , sizeScalarControlAdapter_(
          std::make_shared< SizeScalarControllerAdapter >( coub_ ) )
    , e2EScalarControllerAdapter_(
          std::make_shared< E2EScalarControllerAdapter >( coub_ ) )
    , magneticDirectionScalarControllerAdapter_(
          std::make_shared< MagneticDirectionScalarControllerAdapter >( coub_ ) )
    , magneticScalarControllerAdapter_(
          std::make_shared< MagneticScalarControllerAdapter >( coub_ ) )
    , electricDirectionScalarControllerAdapter_(
          std::make_shared< ElectricDirectionScalarControllerAdapter >( coub_ ) )
    , electricScalaraControllerAdapter_(
          std::make_shared< ElectricScalarControllerAdapter >( coub_ ) )
{
}

// virtual override
Vector ElectronInHomogeneousFieldsController::getCoubSize() const
{
    return coub_->getBorders();
}

// virtual override
void ElectronInHomogeneousFieldsController::addParticle( const Vector& coordinate,
    const Vector& speed, const ParticleOptions& particleOptions )
{
    coub_->addElectron( coordinate, speed, particleOptions );
}

// virtual override
void ElectronInHomogeneousFieldsController::removeParticle( phycoub::IDType id )
{
    coub_->removeParticle( id );
}

PhyCoubControllerWeakPtr ElectronInHomogeneousFieldsController::getPhyCoubController()
{
    return phyCoubController_;
}

GetParticlesAdapterWeakPtr
ElectronInHomogeneousFieldsController::getGetParticleForGLAdapter()
{
    return phyCoubController_;
}

GLRotationControllerWeakPtr
ElectronInHomogeneousFieldsController::getGLRotationController()
{
    return gLRotationController_;
}

VectorControllerAdapterWeakPtr
ElectronInHomogeneousFieldsController::getSizeScalarControllerAdapter()
{
    return sizeScalarControlAdapter_;
}

BoolControllerAdapterWeakPtr
ElectronInHomogeneousFieldsController::getE2EScalarControllerAdapter()
{
    return e2EScalarControllerAdapter_;
}

VectorControllerAdapterWeakPtr
ElectronInHomogeneousFieldsController::getMagneticDirectionControllerAdapter()
{
    return magneticDirectionScalarControllerAdapter_;
}

DoubleControllerAdapterWeakPtr
ElectronInHomogeneousFieldsController::getMagneticScalarControllerAdapter()
{
    return magneticScalarControllerAdapter_;
}

VectorControllerAdapterWeakPtr
ElectronInHomogeneousFieldsController::getElectricDirectionControllerAdapter()
{
    return electricDirectionScalarControllerAdapter_;
}

DoubleControllerAdapterWeakPtr
ElectronInHomogeneousFieldsController::getElectricScalarControllerAdapter()
{
    return electricScalaraControllerAdapter_;
}

} // namespace phyelectroninhomogeneousfields
