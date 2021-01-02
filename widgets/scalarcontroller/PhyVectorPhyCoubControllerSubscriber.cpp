#include "PhyVectorPhyCoubControllerSubscriber.h"

#include "PhyScalarVectorControllerWidget.h"

namespace phywidgets
{

PhyVectorPhyCoubControllerSubscriber::PhyVectorPhyCoubControllerSubscriber(
    PhyScalarVectorControllerWidget* vectorControllerWidget )
    : vectorControllerWidget_( vectorControllerWidget )
{
}

PhyVectorPhyCoubControllerSubscriber::~PhyVectorPhyCoubControllerSubscriber()
{
    release();
}

// virtual override
void PhyVectorPhyCoubControllerSubscriber::onStart()
{
    std::lock_guard< std::mutex > lockGuard( widgetMutex_ );
    if ( vectorControllerWidget_ )
    {
        vectorControllerWidget_->xEdit_->setDisabled( true );
        vectorControllerWidget_->yEdit_->setDisabled( true );
        vectorControllerWidget_->zEdit_->setDisabled( true );
    }
}

// virtual override
void PhyVectorPhyCoubControllerSubscriber::onStop()
{
    std::lock_guard< std::mutex > lockGuard( widgetMutex_ );
    if ( vectorControllerWidget_ )
    {
        vectorControllerWidget_->xEdit_->setDisabled( false );
        vectorControllerWidget_->yEdit_->setDisabled( false );
        vectorControllerWidget_->zEdit_->setDisabled( false );
    }
}

void PhyVectorPhyCoubControllerSubscriber::release()
{
    std::lock_guard< std::mutex > lockGuard( widgetMutex_ );
    vectorControllerWidget_ = nullptr;
}

} // namespace phywidgets
