#ifndef PHYREMOVEPARTICLEPHYCOUBSUBSCRIBER_H
#define PHYREMOVEPARTICLEPHYCOUBSUBSCRIBER_H

#include <mutex>
#include <memory>

#include "PhyCoubControllerSubscriberIface.h"

namespace phywidgets
{

class PhyRemoveParticleWidget;

class PhyRemoveParticlePhyCoubSubscriber : public PhyCoubControllerSubscriberIface
{
  public:
    explicit PhyRemoveParticlePhyCoubSubscriber(
        PhyRemoveParticleWidget* phyRemoveParticleWidget );
    virtual ~PhyRemoveParticlePhyCoubSubscriber() override;

    // Implementation of PhyCoubControllerSubscriberIface
    virtual void onStart() override;
    virtual void onStop() override;

    void release();

  private:
    PhyRemoveParticleWidget* phyRemoveParticleWidget_;
    std::mutex widgetMutex_;
};

using PhyRemoveParticlePhyCoubSubscriberPtr
    = std::shared_ptr< PhyRemoveParticlePhyCoubSubscriber >;

} // namespace phywidgets

#endif // PHYREMOVEPARTICLEPHYCOUBSUBSCRIBER_H
