#include "PhyParticleOptionsControllerWidget.h"

#include <QDoubleValidator>

namespace phywidgets
{

PhyParticleOptionsControllerWidget::PhyParticleOptionsControllerWidget( QWidget* widget )
    : widgetLayout_( new QVBoxLayout( this ) )
    , mainBox_( new QGroupBox( this ) )
    , mainVerticalLayout_( new QVBoxLayout( this ) )
    , weightLineEdit_( new QLineEdit( this ) )
    , weightLabel_( new QLabel( this ) )
    , weightLayout_( new QVBoxLayout( this ) )
    , chargeLineEdit_( new QLineEdit( this ) )
    , chargeLabel_( new QLabel( this ) )
    , chargeLayout_( new QVBoxLayout( this ) )
    , applyChangesButton_( new QPushButton( this ) )
{
    config();
    widget->setLayout( widgetLayout_ );

    QObject::connect(
        applyChangesButton_, SIGNAL( clicked() ), this, SLOT( onApplyChangeClicked() ) );
}

void PhyParticleOptionsControllerWidget::setParticleOptionsControllerAdapter(
    ParticleOptionsControllerAdapterWeakPtr particleOptionstControllerAdapterWeak )
{
    particleOptionstControllerAdapterWeak_ = particleOptionstControllerAdapterWeak;
    if ( auto particleOptionstControllerAdapter
        = particleOptionstControllerAdapterWeak_.lock() )
    {
        phycoub::ParticleOptions particlaOptions
            = particleOptionstControllerAdapter->getValue();
        weightLineEdit_->setText( QString::number( particlaOptions.m_ ) );
        chargeLineEdit_->setText( QString::number( particlaOptions.q_ ) );
    }
}

void PhyParticleOptionsControllerWidget::setTitle( QString label )
{
    mainBox_->setTitle( label );
}

void PhyParticleOptionsControllerWidget::onApplyChangeClicked()
{
    if ( auto particleOptionstControllerAdapter
        = particleOptionstControllerAdapterWeak_.lock() )
    {
        const double weight = weightLineEdit_->text().toDouble();
        const double charge = chargeLineEdit_->text().toDouble();

        if ( weight != 0 && charge != 0 )
        {
            phycoub::ParticleOptions particlaOptions{ weight, charge };
            particleOptionstControllerAdapter->setValue( particlaOptions );
        }
        else
        {
            phycoub::ParticleOptions particlaOptions
                = particleOptionstControllerAdapter->getValue();
            weightLineEdit_->setText( QString::number( particlaOptions.m_ ) );
            chargeLineEdit_->setText( QString::number( particlaOptions.q_ ) );
        }
    }
}

void PhyParticleOptionsControllerWidget::config()
{
    widgetLayout_->addWidget( mainBox_ );
    mainBox_->setLayout( mainVerticalLayout_ );

    weightLabel_->setText( tr( "Масса" ) );
    weightLayout_->addWidget( weightLabel_ );
    weightLayout_->addWidget( weightLineEdit_ );
    mainVerticalLayout_->addLayout( weightLayout_ );

    chargeLabel_->setText( tr( "Заряд" ) );
    chargeLayout_->addWidget( chargeLabel_ );
    chargeLayout_->addWidget( chargeLineEdit_ );
    mainVerticalLayout_->addLayout( chargeLayout_ );

    weightLineEdit_->setText( "0" );
    chargeLineEdit_->setText( "0" );

    applyChangesButton_->setText( tr( "Установить" ) );
    mainVerticalLayout_->addWidget( applyChangesButton_ );

    const QDoubleValidator* optionValidator
        = new QDoubleValidator{ -3'000'000'000., 3'000'000'000., 2, this };
    weightLineEdit_->setValidator( optionValidator );
    chargeLineEdit_->setValidator( optionValidator );
}

} // namespace phywidgets
