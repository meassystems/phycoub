#include "PhyScalarVectorControllerWidget.h"

#include <QDoubleValidator>

namespace phywidgets
{

PhyScalarVectorControllerWidget::PhyScalarVectorControllerWidget( QWidget* parent )
    : QWidget( parent )
    , controllerSubscriber_(
          std::make_shared< PhyVectorPhyCoubControllerSubscriber >( this ) )
    , scalarLayout_( new QHBoxLayout( this ) )
    , editWithLabelLayout_( new QVBoxLayout( this ) )
    , editLabel_( new QLabel( this ) )
    , vectorEditLayout_( new QHBoxLayout( this ) )
    , xEditWithLabelLayout_( new QVBoxLayout( this ) )
    , xLabel_( new QLabel( this ) )
    , xEdit_( new QLineEdit( this ) )
    , yEditWithLabelLayout_( new QVBoxLayout( this ) )
    , yLabel_( new QLabel( this ) )
    , yEdit_( new QLineEdit( this ) )
    , zEditWithLabelLayout_( new QVBoxLayout( this ) )
    , zLabel_( new QLabel( this ) )
    , zEdit_( new QLineEdit( this ) )
    , setScalarValueButton_( new QPushButton( this ) )
{
    setLayout( scalarLayout_ );
    configureVectorScalarVaule();

    QObject::connect( setScalarValueButton_, SIGNAL( clicked() ), this,
        SLOT( onSetScalarValueClicked() ) );
}

PhyScalarVectorControllerWidget::~PhyScalarVectorControllerWidget()
{
    controllerSubscriber_->release();
}

void PhyScalarVectorControllerWidget::setScalarController(
    VectorControllerAdapterWeakPtr vectorControllerAdapterWeak )
{
    vectorControllerAdapterWeak_ = vectorControllerAdapterWeak;
    if ( auto vectorControllerAdapter = vectorControllerAdapterWeak_.lock() )
    {
        const phycoub::Vector vector = vectorControllerAdapter->getValue();
        xEdit_->setText( QString::number( vector.x_ ) );
        yEdit_->setText( QString::number( vector.y_ ) );
        zEdit_->setText( QString::number( vector.z_ ) );
    }
}

void PhyScalarVectorControllerWidget::setScalarValueLabel(
    const QString& scalarValueLabel )
{
    editLabel_->setText( scalarValueLabel );
}

PhyCoubControllerSubscriberWeakPtr
PhyScalarVectorControllerWidget::getPhyCoubControllerSubscriber()
{
    return controllerSubscriber_;
}

void PhyScalarVectorControllerWidget::onSetScalarValueClicked()
{
    if ( auto vectorControllerAdapter = vectorControllerAdapterWeak_.lock() )
    {
        phycoub::Vector vector;
        vector.x_ = xEdit_->text().toDouble();
        vector.y_ = yEdit_->text().toDouble();
        vector.z_ = zEdit_->text().toDouble();

        vectorControllerAdapter->setValue( vector );
    }
}

void PhyScalarVectorControllerWidget::configureVectorScalarVaule()
{
    scalarLayout_->addLayout( editWithLabelLayout_ );
    scalarLayout_->addWidget( setScalarValueButton_ );

    editWithLabelLayout_->addWidget( editLabel_ );
    editWithLabelLayout_->addLayout( vectorEditLayout_ );

    vectorEditLayout_->addLayout( xEditWithLabelLayout_ );
    vectorEditLayout_->addLayout( yEditWithLabelLayout_ );
    vectorEditLayout_->addLayout( zEditWithLabelLayout_ );

    xEditWithLabelLayout_->addWidget( xLabel_ );
    xEditWithLabelLayout_->addWidget( xEdit_ );

    yEditWithLabelLayout_->addWidget( yLabel_ );
    yEditWithLabelLayout_->addWidget( yEdit_ );

    zEditWithLabelLayout_->addWidget( zLabel_ );
    zEditWithLabelLayout_->addWidget( zEdit_ );

    xLabel_->setText( tr( "x" ) );
    yLabel_->setText( tr( "y" ) );
    zLabel_->setText( tr( "z" ) );

    const QDoubleValidator* doubleValidator
        = new QDoubleValidator{ -3'000'000'000., 3'000'000'000., 2, this };
    xEdit_->setValidator( doubleValidator );
    yEdit_->setValidator( doubleValidator );
    zEdit_->setValidator( doubleValidator );

    setScalarValueButton_->setText( tr( "Установить" ) );
}

} // namespace phywidgets
