#include "PhyRemoveParticlePhyCoubSubscriber.h"

#include "PhyRemoveParticleWidget.h"

namespace phywidgets
{

PhyRemoveParticlePhyCoubSubscriber::PhyRemoveParticlePhyCoubSubscriber(
    PhyRemoveParticleWidget* phyRemoveParticleWidget )
    : phyRemoveParticleWidget_( phyRemoveParticleWidget )
{
}

PhyRemoveParticlePhyCoubSubscriber::~PhyRemoveParticlePhyCoubSubscriber()
{
    release();
}

// virtual override
void PhyRemoveParticlePhyCoubSubscriber::onStart()
{
    std::lock_guard< std::mutex > lockGuard( widgetMutex_ );
    if ( phyRemoveParticleWidget_ )
    {
        phyRemoveParticleWidget_->removeParticleButton_->setDisabled( true );
    }
}

// virtual override
void PhyRemoveParticlePhyCoubSubscriber::onStop()
{
    std::lock_guard< std::mutex > lockGuard( widgetMutex_ );
    if ( phyRemoveParticleWidget_ )
    {
        phyRemoveParticleWidget_->removeParticleButton_->setDisabled( false );
    }
}

void PhyRemoveParticlePhyCoubSubscriber::release()
{
    std::lock_guard< std::mutex > lockGuard( widgetMutex_ );
    phyRemoveParticleWidget_ = nullptr;
}

} // namespace phywidgets
