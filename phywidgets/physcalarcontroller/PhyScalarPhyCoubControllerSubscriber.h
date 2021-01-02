#ifndef PHYSCALARCONTROLLERSUBSCRIBER_H
#define PHYSCALARCONTROLLERSUBSCRIBER_H

#include <memory>
#include <mutex>

#include "PhyCoubControllerSubscriberIface.h"

namespace phywidgets
{

template< typename ValueType >
class PhyScalarControllerWidgetBase;

template< typename ValueType >
class PhyScalarPhyCoubControllerSubscriber : public PhyCoubControllerSubscriberIface
{
  public:
    PhyScalarPhyCoubControllerSubscriber(
        PhyScalarControllerWidgetBase< ValueType >* widget );
    virtual ~PhyScalarPhyCoubControllerSubscriber() override;

    // Implementation of PhyCoubControllerSubscriberIface
    virtual void onStart() override;
    virtual void onStop() override;

    void release();

  private:
    PhyScalarControllerWidgetBase< ValueType >* widget_;
    std::mutex widgetMutex_;
};

template< typename ValueType >
using PhyScalarPhyCoubControllerSubscriberPtr
    = std::shared_ptr< PhyScalarPhyCoubControllerSubscriber< ValueType > >;

template< typename ValueType >
PhyScalarPhyCoubControllerSubscriber< ValueType >::PhyScalarPhyCoubControllerSubscriber(
    PhyScalarControllerWidgetBase< ValueType >* widget )
    : widget_( widget )
{
}

template< typename ValueType >
PhyScalarPhyCoubControllerSubscriber< ValueType >::~PhyScalarPhyCoubControllerSubscriber()
{
    release();
}

// virtual override
template< typename ValueType >
void PhyScalarPhyCoubControllerSubscriber< ValueType >::onStart()
{
    std::lock_guard< std::mutex > lockGuard( widgetMutex_ );
    if ( widget_ )
    {
        widget_->scalarValueEdit_->setDisabled( true );
        widget_->setScalarValueButton_->setDisabled( true );
    }
}

// virtual override
template< typename ValueType >
void PhyScalarPhyCoubControllerSubscriber< ValueType >::onStop()
{
    std::lock_guard< std::mutex > lockGuard( widgetMutex_ );
    if ( widget_ )
    {
        widget_->scalarValueEdit_->setDisabled( false );
        widget_->setScalarValueButton_->setDisabled( false );
    }
}

template< typename ValueType >
void PhyScalarPhyCoubControllerSubscriber< ValueType >::release()
{
    std::lock_guard< std::mutex > lockGuard( widgetMutex_ );
    widget_ = nullptr;
}

} // namespace phywidgets

#endif // PHYSCALARCONTROLLERSUBSCRIBER_H
