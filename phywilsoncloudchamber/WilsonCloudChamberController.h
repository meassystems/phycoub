#ifndef WILSONCLOUDCHAMBERCONTROLLER_H
#define WILSONCLOUDCHAMBERCONTROLLER_H

#include <memory>

#include "WilsonCloudChamber.h"
#include "GetCoubSizeAdapterIface.h"
#include "GetParticlesAdapterIface.h"
#include "PhyCoubController.h"
#include "ValueControllerAdapterIface.h"
#include "GLRotationController.h"
#include "ScalarControllerAdapters.h"

namespace phywilsoncloudchamber
{

using namespace phycoub;
using namespace phywidgets;

class WilsonCloudChamberController
    : public std::enable_shared_from_this< WilsonCloudChamberController >
    , public GetCoubSizeAdapterIface
{
  public:
    WilsonCloudChamberController();
    virtual ~WilsonCloudChamberController() override = default;

    // Implementation of GetCoubSizeAdapterIface
    virtual Vector getCoubSize() const override;

    PhyCoubControllerWeakPtr getPhyCoubController();
    GetParticlesAdapterWeakPtr getGetParticleForGLAdapter();
    GLRotationControllerWeakPtr getGLRotationController();

    VectorControllerAdapterWeakPtr getSizeScalarControllerAdapter();

    VectorControllerAdapterWeakPtr getMagneticDirectionControllerAdapter();
    DoubleControllerAdapterWeakPtr getMagneticScalarControllerAdapter();

    VectorControllerAdapterWeakPtr getElectricDirectionControllerAdapter();
    DoubleControllerAdapterWeakPtr getElectricScalarControllerAdapter();

    VectorControllerAdapterWeakPtr getElectronSourceDirectionScalarControllerAdapter();
    DoubleControllerAdapterWeakPtr getElectronSourceAngleControllerAdapter();
    DoubleControllerAdapterWeakPtr getElectronSourceBornPeriodControllerAdapter();
    DoubleControllerAdapterWeakPtr getElectronSourceBornEnergyControllerAdapter();

    VectorControllerAdapterWeakPtr getProtonSourceDirectionScalarControllerAdapter();
    DoubleControllerAdapterWeakPtr getProtonSourceAngleControllerAdapter();
    DoubleControllerAdapterWeakPtr getProtonSourceBornPeriodControllerAdapter();
    DoubleControllerAdapterWeakPtr getProtonSourceBornEnergyControllerAdapter();

    VectorControllerAdapterWeakPtr getSpecificSourceDirectionScalarControllerAdapter();
    DoubleControllerAdapterWeakPtr getSpecificSourceAngleControllerAdapter();
    DoubleControllerAdapterWeakPtr getSpecificSourceBornPeriodControllerAdapter();
    DoubleControllerAdapterWeakPtr getSpecificSourceBornEnergyControllerAdapter();

    ParticleOptionsControllerAdapterWeakPtr
    getSpecificSourceParticleOptionsControllerAdapter();

  private:
    WilsonCloudChamberPtr coub_ = nullptr;
    PhyCoubControllerPtr phyCoubController_ = nullptr;
    GLRotationControllerPtr gLRotationController_ = nullptr;

    SizeScalarControllerAdapterPtr sizeScalarControlAdapter_ = nullptr;
    MagneticDirectionScalarControllerAdapterPtr magneticDirectionScalarControllerAdapter_
        = nullptr;
    MagneticScalarControllerAdapterPtr magneticScalarControllerAdapter_ = nullptr;
    ElectricDirectionScalarControllerAdapterPtr electricDirectionScalarControllerAdapter_
        = nullptr;
    ElectricScalarControllerAdapterPtr electricScalaraControllerAdapter_ = nullptr;

    ElectronSourceDirectionScalarControllerAdapterPtr
        electronSourceDirectionScalarControllerAdapter_
        = nullptr;
    ElectronSourceAngleControllerAdapterPtr electronSourceAngleControllerAdapter_
        = nullptr;
    ElectronSourceBornPeriodControllerAdapterPtr
        electronSourceBornPeriodControllerAdapter_
        = nullptr;
    ElectronSourceBornEnergyControllerAdapterPtr
        electronSourceBornEnergyControllerAdapter_
        = nullptr;

    ProtonSourceDirectionScalarControllerAdapterPtr
        protonSourceDirectionScalarControllerAdapter_
        = nullptr;
    ProtonSourceAngleControllerAdapterPtr protonSourceAngleControllerAdapter_ = nullptr;
    ProtonSourceBornPeriodControllerAdapterPtr protonSourceBornPeriodControllerAdapter_
        = nullptr;
    ProtonSourceBornEnergyControllerAdapterPtr protonSourceBornEnergyControllerAdapter_
        = nullptr;

    SpecificSourceDirectionScalarControllerAdapterPtr
        specificSourceDirectionScalarControllerAdapter_
        = nullptr;
    SpecificSourceAngleControllerAdapterPtr specificSourceAngleControllerAdapter_
        = nullptr;
    SpecificSourceBornPeriodControllerAdapterPtr
        specificSourceBornPeriodControllerAdapter_
        = nullptr;
    SpecificSourceBornEnergyControllerAdapterPtr
        specificSourceBornEnergyControllerAdapter_
        = nullptr;

    SpecificSourceParticleOptionsControllerAdapterPtr
        specificSourceParticleOptionsControllerAdapter_
        = nullptr;
};

using WilsonCloudChamberControllerPtr = std::shared_ptr< WilsonCloudChamberController >;

} // namespace phywilsoncloudchamber

#endif // WILSONCLOUDCHAMBERCONTROLLER_H
