#include "PhyAddParticlePhyCoubSubscriber.h"

#include "PhyAddParticleWidget.h"

namespace phywidgets
{

PhyAddParticlePhyCoubSubscriber::PhyAddParticlePhyCoubSubscriber(
    PhyAddParticleWidget* phyAddParticleWidget )
    : phyAddParticleWidget_( phyAddParticleWidget )
{
}

PhyAddParticlePhyCoubSubscriber::~PhyAddParticlePhyCoubSubscriber()
{
    release();
}

// virtual override
void PhyAddParticlePhyCoubSubscriber::onStart()
{
    std::lock_guard< std::mutex > lockGuard( widgetMutex_ );
    if ( phyAddParticleWidget_ )
    {
        phyAddParticleWidget_->addParticleButton_->setDisabled( true );
    }
}

// virtual override
void PhyAddParticlePhyCoubSubscriber::onStop()
{
    std::lock_guard< std::mutex > lockGuard( widgetMutex_ );
    if ( phyAddParticleWidget_ )
    {
        phyAddParticleWidget_->addParticleButton_->setDisabled( false );
    }
}

void PhyAddParticlePhyCoubSubscriber::release()
{
    std::lock_guard< std::mutex > lockGuard( widgetMutex_ );
    phyAddParticleWidget_ = nullptr;
}

} // namespace phywidgets
