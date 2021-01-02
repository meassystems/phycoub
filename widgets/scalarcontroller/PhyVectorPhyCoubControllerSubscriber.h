#ifndef PHYVECTORPHYCOUBCONTROLLERSUBSCRIBER_H
#define PHYVECTORPHYCOUBCONTROLLERSUBSCRIBER_H

#include <mutex>
#include <memory>
#include "PhyCoubControllerSubscriberIface.h"

namespace phywidgets
{

class PhyScalarVectorControllerWidget;

class PhyVectorPhyCoubControllerSubscriber : public PhyCoubControllerSubscriberIface
{
  public:
    PhyVectorPhyCoubControllerSubscriber(
        PhyScalarVectorControllerWidget* phyScalarVectorControllerWidget );

    virtual ~PhyVectorPhyCoubControllerSubscriber() override;

    // Implementation of PhyCoubControllerSubscriberIface
    virtual void onStart() override;
    virtual void onStop() override;

    void release();

  private:
    PhyScalarVectorControllerWidget* vectorControllerWidget_;
    std::mutex widgetMutex_;
};

using PhyVectorPhyCoubControllerSubscriberPtr
    = std::shared_ptr< PhyVectorPhyCoubControllerSubscriber >;

} // namespace phywidgets

#endif // PHYVECTORPHYCOUBCONTROLLERSUBSCRIBER_H
