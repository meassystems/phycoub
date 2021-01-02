#include "PhyCoubControllerWidget.h"

#include <QDoubleValidator>

namespace phywidgets
{

PhyCoubControllerWidget::PhyCoubControllerWidget( QWidget* parent )
    : QWidget( parent )
    , layout_( new QVBoxLayout( this ) )
    , controlGroup_( new QGroupBox( this ) )
    , controlGroupLayout_( new QVBoxLayout( this ) )
    , startButton_( new QPushButton( this ) )
    , iterationButton_( new QPushButton( this ) )
    , stopButton_( new QPushButton( this ) )
    , optionGroup_( new QGroupBox( this ) )
    , optionGroupLayout_( new QVBoxLayout( this ) )
    , deltaTimeLayout_( new QHBoxLayout( this ) )
    , deltaTimeEditLayout_( new QVBoxLayout( this ) )
    , deltaTimeLabel_( new QLabel( this ) )
    , deltaTimeEdit_( new QLineEdit( this ) )
    , setDeltaTimeButton_( new QPushButton( this ) )
    , experimentTimeLayout_( new QHBoxLayout( this ) )
    , experimentTimeViewLayout_( new QVBoxLayout( this ) )
    , experimentTimeLabel_( new QLabel( this ) )
    , experimentTimeView_( new QLineEdit( this ) )
    , resetExperimentTimeButton_( new QPushButton( this ) )
{
    configureControlGroup();
    configureOptionsGroup();

    setLayout( layout_ );
    layout_->addWidget( controlGroup_ );
    layout_->addWidget( optionGroup_ );

    QObject::connect( startButton_, SIGNAL( clicked() ), this, SLOT( onStartClicked() ) );
    QObject::connect(
        iterationButton_, SIGNAL( clicked() ), this, SLOT( onIterationClicked() ) );
    QObject::connect( stopButton_, SIGNAL( clicked() ), this, SLOT( onStopClicked() ) );

    QObject::connect(
        setDeltaTimeButton_, SIGNAL( clicked() ), this, SLOT( onSetDeltaTimeClicked() ) );
    QObject::connect( resetExperimentTimeButton_, SIGNAL( clicked() ), this,
        SLOT( onResetExperimentTimeClicked() ) );

    QObject::connect( &updateExperimentTimeTimer_, SIGNAL( timeout() ), this,
        SLOT( updateExperimentTime() ) );
    updateExperimentTimeTimer_.start( 200 );

    controllerSubscriber_ = std::make_shared< PhyCoubControllerSubscriber >( this );
}

PhyCoubControllerWidget::~PhyCoubControllerWidget()
{
    controllerSubscriber_->release();
}

void PhyCoubControllerWidget::setPhyCoubController(
    PhyCoubControllerWeakPtr phyCoubControllerWeak )
{
    phyCoubControllerWeak_ = phyCoubControllerWeak;
    if ( auto phyCoubController = phyCoubControllerWeak_.lock() )
    {
        phyCoubController->subscribe( controllerSubscriber_ );

        deltaTimeEdit_->setText( QString::number( phyCoubController->getDeltaTime() ) );
        experimentTimeView_->setText(
            QString::number( phyCoubController->getExperimentTime() ) );
    }
}

void PhyCoubControllerWidget::onStartClicked()
{
    if ( auto phyCoubController = phyCoubControllerWeak_.lock() )
    {
        phyCoubController->startCalculation();
    }
}

void PhyCoubControllerWidget::onIterationClicked()
{
    if ( auto phyCoubController = phyCoubControllerWeak_.lock() )
    {
        phyCoubController->calculateOnce();
    }
}

void PhyCoubControllerWidget::onStopClicked()
{
    if ( auto phyCoubController = phyCoubControllerWeak_.lock() )
    {
        phyCoubController->stopCalculation();
    }
}

void PhyCoubControllerWidget::onSetDeltaTimeClicked()
{
    if ( auto phyCoubController = phyCoubControllerWeak_.lock() )
    {
        phyCoubController->setDeltaTime( deltaTimeEdit_->text().toDouble() );
    }
}

void PhyCoubControllerWidget::onResetExperimentTimeClicked()
{
    if ( auto phyCoubController = phyCoubControllerWeak_.lock() )
    {
        phyCoubController->resetToZeroExperimentTime();
    }
}

void PhyCoubControllerWidget::updateExperimentTime()
{
    if ( auto phyCoubController = phyCoubControllerWeak_.lock() )
    {
        experimentTimeView_->setText(
            QString::number( phyCoubController->getExperimentTime() ) );
    }
}

void PhyCoubControllerWidget::configureControlGroup()
{
    controlGroup_->setLayout( controlGroupLayout_ );
    controlGroup_->setTitle( tr( "Управление" ) );

    controlGroupLayout_->addWidget( startButton_ );
    controlGroupLayout_->addWidget( iterationButton_ );
    controlGroupLayout_->addWidget( stopButton_ );

    startButton_->setText( tr( "Старт" ) );
    iterationButton_->setText( tr( "Итерация" ) );
    stopButton_->setText( tr( "Стоп" ) );
}

void PhyCoubControllerWidget::configureOptionsGroup()
{
    optionGroup_->setLayout( optionGroupLayout_ );
    optionGroup_->setTitle( tr( "Настройки" ) );

    optionGroupLayout_->addLayout( deltaTimeLayout_ );
    optionGroupLayout_->addLayout( experimentTimeLayout_ );

    deltaTimeLayout_->addLayout( deltaTimeEditLayout_ );
    deltaTimeLayout_->addWidget( setDeltaTimeButton_ );

    deltaTimeEditLayout_->addWidget( deltaTimeLabel_ );
    deltaTimeEditLayout_->addWidget( deltaTimeEdit_ );

    const QDoubleValidator* deltaTimeValidator = new QDoubleValidator{ 0, 1, 2, this };
    deltaTimeEdit_->setValidator( deltaTimeValidator );
    deltaTimeLabel_->setText( tr( "Шаг по времени" ) );
    setDeltaTimeButton_->setText( tr( "Установить" ) );

    experimentTimeLayout_->addLayout( experimentTimeViewLayout_ );
    experimentTimeLayout_->addWidget( resetExperimentTimeButton_ );

    experimentTimeViewLayout_->addWidget( experimentTimeLabel_ );
    experimentTimeViewLayout_->addWidget( experimentTimeView_ );
    experimentTimeLabel_->setText( tr( "Время эксперимента" ) );
    experimentTimeView_->setDisabled( true );
    resetExperimentTimeButton_->setText( "Сбросить время эксперимента" );
}

} // namespace phywidgets
