#ifndef PHYCOUBCONTROLLERSUBSCRIBERIFACE_H
#define PHYCOUBCONTROLLERSUBSCRIBERIFACE_H

#include <memory>

namespace phywidgets
{

class PhyCoubControllerSubscriberIface
{
  public:
    virtual ~PhyCoubControllerSubscriberIface() = default;

    virtual void onStart() = 0;
    virtual void onStop() = 0;
};

using PhyCoubControllerSubscriberWeakPtr
    = std::weak_ptr< PhyCoubControllerSubscriberIface >;

} // namespace phywidgets

#endif // PHYCOUBCONTROLLERSUBSCRIBERIFACE_H
