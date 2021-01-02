#ifndef PHYCOUBCONTROLLER_H
#define PHYCOUBCONTROLLER_H

#include <mutex>
#include <future>
#include <memory>

#include "PhyCoub.h"
#include "PhyCoubControllerSubscriberIface.h"
#include "GetParticlesAdapterIface.h"

namespace phywidgets
{

class PhyCoubController final : public GetParticlesAdapterIface
{
  public:
    PhyCoubController( phycoub::PhyCoubPtr coub );
    virtual ~PhyCoubController() override;

    // Implementation of GetParticlesForGLAdapterIface
    virtual phycoub::ParticleGroupList getParticles() const override;

    void startCalculation();
    void calculateOnce();
    void stopCalculation();

    void setDeltaTime( double dt );
    double getDeltaTime() const;

    double getExperimentTime() const;
    void resetToZeroExperimentTime();

    void subscribe( PhyCoubControllerSubscriberWeakPtr subscriber );

  private:
    mutable std::mutex processMutex_;

    mutable phycoub::ParticleGroupList particlesForGL_;
    mutable std::mutex particlesForGLMutex_;

    bool isCalculating_ = false;
    std::future< void > calculationThread_;
    phycoub::PhyCoubPtr coub_;

    std::list< PhyCoubControllerSubscriberWeakPtr > subscribers_;
};

using PhyCoubControllerWeakPtr = std::weak_ptr< PhyCoubController >;
using PhyCoubControllerPtr = std::shared_ptr< PhyCoubController >;

} // namespace phywidgets

#endif // PHYCOUBCONTROLLER_H
