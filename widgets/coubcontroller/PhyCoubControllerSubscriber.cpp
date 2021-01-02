#include "PhyCoubControllerSubscriber.h"

#include "PhyCoubControllerWidget.h"

namespace phywidgets
{

PhyCoubControllerSubscriber::PhyCoubControllerSubscriber(
    PhyCoubControllerWidget* widget )
    : widget_( widget )
{
}

PhyCoubControllerSubscriber::~PhyCoubControllerSubscriber()
{
    release();
}

// virtual override
void PhyCoubControllerSubscriber::onStart()
{
    std::lock_guard< std::mutex > lockGuard( widgetMutex_ );
    if ( widget_ )
    {
        widget_->deltaTimeEdit_->setDisabled( true );
    }
}

// virtual override
void PhyCoubControllerSubscriber::onStop()
{
    std::lock_guard< std::mutex > lockGuard( widgetMutex_ );
    if ( widget_ )
    {
        widget_->deltaTimeEdit_->setDisabled( false );
    }
}

void PhyCoubControllerSubscriber::release()
{
    std::lock_guard< std::mutex > lockGuard( widgetMutex_ );
    widget_ = nullptr;
}

} // namespace phywidgets
