#include "PhyBoolPhyCoubControllerSubscriber.h"

#include "PhyScalarBoolControllerWidget.h"

namespace phywidgets
{

PhyBoolPhyCoubControllerSubscriber::PhyBoolPhyCoubControllerSubscriber(
    PhyScalarBoolControllerWidget* boolControllerWidget )
    : boolControllerWidget_( boolControllerWidget )
{
}

PhyBoolPhyCoubControllerSubscriber::~PhyBoolPhyCoubControllerSubscriber()
{
    release();
}

// virtual override
void PhyBoolPhyCoubControllerSubscriber::onStart()
{
    std::lock_guard< std::mutex > lockGuard( widgetMutex_ );
    if ( boolControllerWidget_ )
    {
        boolControllerWidget_->editScalarValue_->setDisabled( true );
    }
}

// virtual override
void PhyBoolPhyCoubControllerSubscriber::onStop()
{
    std::lock_guard< std::mutex > lockGuard( widgetMutex_ );
    if ( boolControllerWidget_ )
    {
        boolControllerWidget_->editScalarValue_->setDisabled( false );
    }
}

void PhyBoolPhyCoubControllerSubscriber::release()
{
    std::lock_guard< std::mutex > lockGuard( widgetMutex_ );
    boolControllerWidget_ = nullptr;
}

} // namespace phywidgets
