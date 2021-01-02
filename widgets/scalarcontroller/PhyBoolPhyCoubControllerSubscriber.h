#ifndef PHYBOOLPHYCOUBCONTROLLERSUBSCRIBER_H
#define PHYBOOLPHYCOUBCONTROLLERSUBSCRIBER_H

#include <mutex>
#include <memory>
#include "PhyCoubControllerSubscriberIface.h"

namespace phywidgets
{

class PhyScalarBoolControllerWidget;

class PhyBoolPhyCoubControllerSubscriber : public PhyCoubControllerSubscriberIface
{
  public:
    PhyBoolPhyCoubControllerSubscriber(
        PhyScalarBoolControllerWidget* boolControllerWidget );
    virtual ~PhyBoolPhyCoubControllerSubscriber() override;

    // Implementation of PhyCoubControllerSubscriberIface
    virtual void onStart() override;
    virtual void onStop() override;

    void release();

  private:
    PhyScalarBoolControllerWidget* boolControllerWidget_;
    std::mutex widgetMutex_;
};

using PhyBoolPhyCoubControllerSubscriberPtr
    = std::shared_ptr< PhyBoolPhyCoubControllerSubscriber >;

} // namespace phywidgets

#endif // PHYBOOLPHYCOUBCONTROLLERSUBSCRIBER_H
