#ifndef MAGNETRONCONTROLLER_H
#define MAGNETRONCONTROLLER_H

#include <memory>

#include "Magnetron.h"
#include "GetCoubSizeAdapterIface.h"
#include "GetParticlesAdapterIface.h"
#include "PhyCoubController.h"
#include "ValueControllerAdapterIface.h"
#include "GLRotationController.h"
#include "ScalarControllerAdapters.h"

namespace phymagnetron
{

using namespace phycoub;
using namespace phywidgets;

class MagnetronController
    : public std::enable_shared_from_this< MagnetronController >
    , public GetCoubSizeAdapterIface
{
  public:
    MagnetronController();
    virtual ~MagnetronController() override = default;

    // Implementation of GetCoubSizeAdapterIface
    virtual Vector getCoubSize() const override;

    PhyCoubControllerWeakPtr getPhyCoubController();
    GetParticlesAdapterWeakPtr getGetParticleForGLAdapter();
    GLRotationControllerWeakPtr getGLRotationController();

    DoubleControllerAdapterWeakPtr getRadiusScalarControllerAdapter();
    DoubleControllerAdapterWeakPtr getHeightScalarControllerAdapter();

    DoubleControllerAdapterWeakPtr getMagneticScalarControllerAdapter();
    DoubleControllerAdapterWeakPtr getElectricScalarControllerAdapter();

    DoubleControllerAdapterWeakPtr getEnergyScalarControllerAdapter();
    LongControllerAdapterWeakPtr getLifeParticleCountScalarControllerAdapter();

  private:
    MagnetronPtr magnetron_ = nullptr;
    PhyCoubControllerPtr phyCoubController_ = nullptr;
    GLRotationControllerPtr gLRotationController_ = nullptr;

    RadiusScalarControllerAdapterPtr radiusScalarControllerAdapter_ = nullptr;
    HeightScalarControllerAdapterPtr heightScalarControllerAdapter_ = nullptr;
    MagneticScalarControllerAdapterPtr magneticScalarControllerAdapter_ = nullptr;
    ElectricScalarControllerAdapterPtr electricScalarControllerAdapter_ = nullptr;
    EnergyScalarControllerAdapterPtr energyScalarControllerAdapter_ = nullptr;
    LifeParticleCountScalarControllerAdapterPtr lifeParticleCountScalarControllerAdapter_
        = nullptr;
};

using MagnetronControllerPtr = std::shared_ptr< MagnetronController >;

} // namespace phymagnetron

#endif // MAGNETRONCONTROLLER_H
