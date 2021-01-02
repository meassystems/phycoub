#ifndef ELECTRONINHOMOGENEOUSFIELDSCONTROLLER_H
#define ELECTRONINHOMOGENEOUSFIELDSCONTROLLER_H

#include <memory>

#include "ElectronInHomogeneousFieldsCoub.h"
#include "GetCoubSizeAdapterIface.h"
#include "AddParticleControllerAdapterIface.h"
#include "ParticleRemoveControllerAdapterIface.h"
#include "GetParticlesAdapterIface.h"
#include "PhyCoubController.h"
#include "ValueControllerAdapterIface.h"
#include "GLRotationController.h"
#include "ScalarControllerAdapters.h"

namespace phyelectroninhomogeneousfields
{

using namespace phycoub;
using namespace phywidgets;

class ElectronInHomogeneousFieldsController
    : public std::enable_shared_from_this< ElectronInHomogeneousFieldsController >
    , public GetCoubSizeAdapterIface
    , public AddParticleControllerAdapterIface
    , public ParticleRemoveControllerAdapterIface
{
  public:
    ElectronInHomogeneousFieldsController();
    virtual ~ElectronInHomogeneousFieldsController() override = default;

    // Implementation of GetCoubSizeAdapterIface
    virtual Vector getCoubSize() const override;

    // Implementation of AddParticleControllerAdapterIface
    virtual void addParticle( const Vector& coordinate, const Vector& speed,
        const ParticleOptions& particleOptions ) override;

    // Implementation of ParticleRemoveControllerAdapterIface
    virtual void removeParticle( phycoub::IDType id ) override;

    PhyCoubControllerWeakPtr getPhyCoubController();
    GetParticlesAdapterWeakPtr getGetParticleForGLAdapter();
    GLRotationControllerWeakPtr getGLRotationController();

    VectorControllerAdapterWeakPtr getSizeScalarControllerAdapter();
    BoolControllerAdapterWeakPtr getE2EScalarControllerAdapter();

    VectorControllerAdapterWeakPtr getMagneticDirectionControllerAdapter();
    DoubleControllerAdapterWeakPtr getMagneticScalarControllerAdapter();

    VectorControllerAdapterWeakPtr getElectricDirectionControllerAdapter();
    DoubleControllerAdapterWeakPtr getElectricScalarControllerAdapter();

  private:
    ElectronInHomogeneousFieldsCoubPtr coub_ = nullptr;
    PhyCoubControllerPtr phyCoubController_ = nullptr;
    GLRotationControllerPtr gLRotationController_ = nullptr;

    SizeScalarControllerAdapterPtr sizeScalarControlAdapter_ = nullptr;
    E2EScalarControllerAdapterPtr e2EScalarControllerAdapter_ = nullptr;
    MagneticDirectionScalarControllerAdapterPtr magneticDirectionScalarControllerAdapter_
        = nullptr;
    MagneticScalarControllerAdapterPtr magneticScalarControllerAdapter_ = nullptr;
    ElectricDirectionScalarControllerAdapterPtr electricDirectionScalarControllerAdapter_
        = nullptr;
    ElectricScalarControllerAdapterPtr electricScalaraControllerAdapter_ = nullptr;
};

using ElectronInHomogeneousFieldsControllerPtr
    = std::shared_ptr< ElectronInHomogeneousFieldsController >;

} // namespace phyelectroninhomogeneousfields

#endif // ELECTRONINHOMOGENEOUSFIELDSCONTROLLER_H
