#include "PhyRemoveParticleWidget.h"

#include <QIntValidator>

namespace phywidgets
{

PhyRemoveParticleWidget::PhyRemoveParticleWidget( QWidget* parent )
    : QWidget( parent )
    , coubControllerSubscriber_(
          std::make_shared< PhyRemoveParticlePhyCoubSubscriber >( this ) )
    , layout_( new QHBoxLayout( this ) )
    , indexParticleLayout_( new QVBoxLayout( this ) )
    , indexParticleLabel_( new QLabel( this ) )
    , indexParticleEdit_( new QLineEdit( this ) )
    , removeParticleButton_( new QPushButton( this ) )
{
    configureInputs();
    setLayout( layout_ );
}

void PhyRemoveParticleWidget::setRemoveParticleControllerAdapter(
    ParticleRemoveControllerAdapterWeakPtr particleRemoveControllerAdapterWeak )
{
    particleRemoveControllerAdapterWeak_ = particleRemoveControllerAdapterWeak;
}

PhyCoubControllerSubscriberWeakPtr PhyRemoveParticleWidget::getPhyCoubSubsriber()
{
    return coubControllerSubscriber_;
}

void PhyRemoveParticleWidget::removeParticle()
{
    if ( auto particleRemoveControllerAdapter
        = particleRemoveControllerAdapterWeak_.lock() )
    {
        particleRemoveControllerAdapter->removeParticle(
            indexParticleEdit_->text().toInt() );
    }
}

void PhyRemoveParticleWidget::configureInputs()
{
    indexParticleLabel_->setText( tr( "Идентификатор" ) );
    indexParticleLayout_->addWidget( indexParticleLabel_ );
    indexParticleLayout_->addWidget( indexParticleEdit_ );

    layout_->addLayout( indexParticleLayout_ );
    layout_->addWidget( removeParticleButton_ );
    removeParticleButton_->setText( tr( "Удалить" ) );

    const QIntValidator* indexValidator = new QIntValidator{ 0, 1'000'000, this };
    indexParticleEdit_->setValidator( indexValidator );

    QObject::connect(
        removeParticleButton_, SIGNAL( clicked() ), this, SLOT( removeParticle() ) );
}

} // namespace phywidgets
