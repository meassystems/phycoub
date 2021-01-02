#include "PhyScalarBoolControllerWidget.h"

namespace phywidgets
{

PhyScalarBoolControllerWidget::PhyScalarBoolControllerWidget( QWidget* parent )
    : QWidget( parent )
    , controllerSubscriber_(
          std::make_shared< PhyBoolPhyCoubControllerSubscriber >( this ) )
    , scalarLayout_( new QHBoxLayout( this ) )
    , editScalarValue_( new QCheckBox( this ) )
    , setScalarValueButton_( new QPushButton( this ) )
{
    setLayout( scalarLayout_ );
    configureBoolScalarVaule();

    QObject::connect( setScalarValueButton_, SIGNAL( clicked() ), this,
        SLOT( onSetScalarValueClicked() ) );
}

PhyScalarBoolControllerWidget::~PhyScalarBoolControllerWidget()
{
    controllerSubscriber_->release();
}

void PhyScalarBoolControllerWidget::setScalarController(
    BoolControllerAdapterWeakPtr boolControllerAdapterWeak )
{
    boolControllerAdapterWeak_ = boolControllerAdapterWeak;
}

void PhyScalarBoolControllerWidget::setScalarValueLabel( const QString& scalarValueLabel )
{
    editScalarValue_->setText( scalarValueLabel );
}

PhyCoubControllerSubscriberWeakPtr
PhyScalarBoolControllerWidget::getPhyCoubControllerSubscriber()
{
    return controllerSubscriber_;
}

void PhyScalarBoolControllerWidget::onSetScalarValueClicked()
{
    if ( auto boolControllerAdapter = boolControllerAdapterWeak_.lock() )
    {
        boolControllerAdapter->setValue( editScalarValue_->isChecked() );
    }
}

void PhyScalarBoolControllerWidget::configureBoolScalarVaule()
{
    scalarLayout_->addWidget( editScalarValue_ );
    scalarLayout_->addWidget( setScalarValueButton_ );
    setScalarValueButton_->setText( "Установить" );
}

} // namespace phywidgets
