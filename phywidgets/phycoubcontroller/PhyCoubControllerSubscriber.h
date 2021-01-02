#ifndef PHYCOUBCONTROLLERSUBSRIBER_H
#define PHYCOUBCONTROLLERSUBSRIBER_H

#include <memory>
#include <mutex>

#include "PhyCoubControllerSubscriberIface.h"

namespace phywidgets
{

class PhyCoubControllerWidget;

class PhyCoubControllerSubscriber final : public PhyCoubControllerSubscriberIface
{
  public:
    PhyCoubControllerSubscriber( PhyCoubControllerWidget* widget );
    virtual ~PhyCoubControllerSubscriber() override;

    // Implementation of PhyCoubControllerSubscriberIface
    virtual void onStart() override;
    virtual void onStop() override;

    void release();

  private:
    PhyCoubControllerWidget* widget_;
    std::mutex widgetMutex_;
};

} // namespace phywidgets

#endif // PHYCOUBCONTROLLERSUBSRIBER_H
