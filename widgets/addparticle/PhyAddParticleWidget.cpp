#include "PhyAddParticleWidget.h"

#include <QDoubleValidator>

#include "Vector.h"

namespace phywidgets
{

PhyAddParticleWidget::PhyAddParticleWidget( QWidget* parent )
    : QWidget( parent )
    , coubControllerSubscriber_(
          std::make_shared< PhyAddParticlePhyCoubSubscriber >( this ) )
    , addParticleLayout_( new QHBoxLayout( this ) )
    , coordinateXLayout_( new QVBoxLayout( this ) )
    , coordinateYLayout_( new QVBoxLayout( this ) )
    , coordinateZLayout_( new QVBoxLayout( this ) )
    , coordinateXLabel_( new QLabel( this ) )
    , coordinateYLabel_( new QLabel( this ) )
    , coordinateZLabel_( new QLabel( this ) )
    , coordinateXParticleEdit_( new QLineEdit( this ) )
    , coordinateYParticleEdit_( new QLineEdit( this ) )
    , coordinateZParticleEdit_( new QLineEdit( this ) )
    , speedXLayout_( new QVBoxLayout( this ) )
    , speedYLayout_( new QVBoxLayout( this ) )
    , speedZLayout_( new QVBoxLayout( this ) )
    , speedXLabel_( new QLabel( this ) )
    , speedYLabel_( new QLabel( this ) )
    , speedZLabel_( new QLabel( this ) )
    , speedXParticleEdit_( new QLineEdit( this ) )
    , speedYParticleEdit_( new QLineEdit( this ) )
    , speedZParticleEdit_( new QLineEdit( this ) )
    , weightLayout_( new QVBoxLayout( this ) )
    , chargeLayout_( new QVBoxLayout( this ) )
    , weightLabel_( new QLabel( this ) )
    , chargeLabel_( new QLabel( this ) )
    , weightParticleEdit_( new QLineEdit( this ) )
    , chargeParticleEdit_( new QLineEdit( this ) )
    , addParticleButton_( new QPushButton( this ) )
{
    configureInputs();
    setLayout( addParticleLayout_ );
}

void PhyAddParticleWidget::setAddParticleControllerAdapter(
    AddParticleControllerAdapterWeakPtr addParticleControllerAdapterWeak )
{
    addParticleControllerAdapterWeak_ = addParticleControllerAdapterWeak;
}

void PhyAddParticleWidget::setGetCoubSizeAdapter(
    GetCoubSizeAdapterWeakPtr getCoubSizeAdapterWeak )
{
    getCoubSizeAdapterWeak_ = getCoubSizeAdapterWeak;
}

PhyCoubControllerSubscriberWeakPtr PhyAddParticleWidget::getPhyCoubSubsriber()
{
    return coubControllerSubscriber_;
}

void PhyAddParticleWidget::setDefaultOptions( ParticleOptions options )
{
    defaultParticleOptions_ = options;
    weightParticleEdit_->setText( QString::number( defaultParticleOptions_.m_ ) );
    chargeParticleEdit_->setText( QString::number( defaultParticleOptions_.q_ ) );
}

void PhyAddParticleWidget::addParticle()
{
    using namespace phycoub;

    if ( auto addParticleControllerAdapter = addParticleControllerAdapterWeak_.lock() )
        if ( auto getCoubSizeAdapter = getCoubSizeAdapterWeak_.lock() )
        {
            {
                const Vector& coubSize = getCoubSizeAdapter->getCoubSize();
                const Vector coordinate{ coordinateXParticleEdit_->text().toDouble()
                        * coubSize.x_,
                    coordinateYParticleEdit_->text().toDouble() * coubSize.y_,
                    coordinateZParticleEdit_->text().toDouble() * coubSize.z_ };

                const Vector speed{ speedXParticleEdit_->text().toDouble(),
                    speedYParticleEdit_->text().toDouble(),
                    speedZParticleEdit_->text().toDouble() };

                const ParticleOptions options{ weightParticleEdit_->text().toDouble(),
                    chargeParticleEdit_->text().toDouble() };

                addParticleControllerAdapter->addParticle( coordinate, speed, options );
            }
        }
}

void PhyAddParticleWidget::configureInputs()
{
    coordinateXLabel_->setText( tr( "Координата X" ) );
    coordinateXLayout_->addWidget( coordinateXLabel_ );
    coordinateXLayout_->addWidget( coordinateXParticleEdit_ );
    addParticleLayout_->addLayout( coordinateXLayout_ );

    coordinateYLabel_->setText( tr( "Координата Y" ) );
    coordinateYLayout_->addWidget( coordinateYLabel_ );
    coordinateYLayout_->addWidget( coordinateYParticleEdit_ );
    addParticleLayout_->addLayout( coordinateYLayout_ );

    coordinateZLabel_->setText( tr( "Координата Z" ) );
    coordinateZLayout_->addWidget( coordinateZLabel_ );
    coordinateZLayout_->addWidget( coordinateZParticleEdit_ );
    addParticleLayout_->addLayout( coordinateZLayout_ );

    speedXLabel_->setText( tr( "Пр. скорости X [м/c]" ) );
    speedXLayout_->addWidget( speedXLabel_ );
    speedXLayout_->addWidget( speedXParticleEdit_ );
    addParticleLayout_->addLayout( speedXLayout_ );

    speedYLabel_->setText( tr( "Пр. скорости Y [м/c]" ) );
    speedYLayout_->addWidget( speedYLabel_ );
    speedYLayout_->addWidget( speedYParticleEdit_ );
    addParticleLayout_->addLayout( speedYLayout_ );

    speedZLabel_->setText( tr( "Пр. скорости Z [м/c]" ) );
    speedZLayout_->addWidget( speedZLabel_ );
    speedZLayout_->addWidget( speedZParticleEdit_ );
    addParticleLayout_->addLayout( speedZLayout_ );

    weightLabel_->setText( tr( "Масса [кг]" ) );
    weightLayout_->addWidget( weightLabel_ );
    weightLayout_->addWidget( weightParticleEdit_ );
    addParticleLayout_->addLayout( weightLayout_ );

    chargeLabel_->setText( tr( "Заряд [Кл]" ) );
    chargeLayout_->addWidget( chargeLabel_ );
    chargeLayout_->addWidget( chargeParticleEdit_ );
    addParticleLayout_->addLayout( chargeLayout_ );

    addParticleLayout_->addWidget( addParticleButton_ );

    const QDoubleValidator* coordinatValidator = new QDoubleValidator{ 0, 1, 2, this };
    coordinateXParticleEdit_->setValidator( coordinatValidator );
    coordinateYParticleEdit_->setValidator( coordinatValidator );
    coordinateZParticleEdit_->setValidator( coordinatValidator );

    coordinateXParticleEdit_->setText( "0" );
    coordinateYParticleEdit_->setText( "0" );
    coordinateZParticleEdit_->setText( "0" );

    const QDoubleValidator* speedValidator
        = new QDoubleValidator{ -3'000'000'000., 3'000'000'000., 2, this };
    speedXParticleEdit_->setValidator( speedValidator );
    speedYParticleEdit_->setValidator( speedValidator );
    speedZParticleEdit_->setValidator( speedValidator );

    speedXParticleEdit_->setText( "0" );
    speedYParticleEdit_->setText( "0" );
    speedZParticleEdit_->setText( "0" );

    const QDoubleValidator* particleOptionsValidator
        = new QDoubleValidator{ 0, 3'000'000'000., 2, this };
    weightParticleEdit_->setValidator( particleOptionsValidator );
    chargeParticleEdit_->setValidator( particleOptionsValidator );

    addParticleButton_->setText( tr( "Добавить" ) );

    QObject::connect(
        addParticleButton_, SIGNAL( clicked() ), this, SLOT( addParticle() ) );
}

}; // namespace phywidgets
