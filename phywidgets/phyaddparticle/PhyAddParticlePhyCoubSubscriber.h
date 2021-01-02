#ifndef PHYADDPARTICLEPHYCOUBSUBSCRIBER_H
#define PHYADDPARTICLEPHYCOUBSUBSCRIBER_H

#include <mutex>
#include <memory>

#include "PhyCoubControllerSubscriberIface.h"

namespace phywidgets
{

class PhyAddParticleWidget;

class PhyAddParticlePhyCoubSubscriber : public PhyCoubControllerSubscriberIface
{
  public:
    explicit PhyAddParticlePhyCoubSubscriber(
        PhyAddParticleWidget* phyAddParticleWidget );
    virtual ~PhyAddParticlePhyCoubSubscriber() override;

    // Implementation of PhyCoubControllerSubscriberIface
    virtual void onStart() override;
    virtual void onStop() override;

    void release();

  private:
    PhyAddParticleWidget* phyAddParticleWidget_;
    std::mutex widgetMutex_;
};

using PhyAddParticlePhyCoubSubscriberPtr
    = std::shared_ptr< PhyAddParticlePhyCoubSubscriber >;

} // namespace phywidgets

#endif // PHYADDPARTICLEPHYCOUBSUBSCRIBER_H
