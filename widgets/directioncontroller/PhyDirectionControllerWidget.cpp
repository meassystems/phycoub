#include "PhyDirectionControllerWidget.h"

namespace phywidgets
{

PhyDirectionControllerWidget::PhyDirectionControllerWidget( QWidget* parent )
    : QWidget( parent )
    , layout_( new QHBoxLayout( this ) )
    , thetaLayout_( new QVBoxLayout( this ) )
    , thetaLabel_( new QLabel( QChar( 0x98, 0x03 ), this ) )
    , theta_( new QDoubleSpinBox( this ) )
    , alphaLayout_( new QVBoxLayout( this ) )
    , alphaLabel_( new QLabel( QChar( 0xb1, 0x03 ), this ) )
    , alpha_( new QDoubleSpinBox( this ) )
{
    configureSpinBox();

    setLayout( layout_ );
    layout_->addLayout( thetaLayout_ );
    layout_->addLayout( alphaLayout_ );

    QObject::connect(
        theta_, SIGNAL( valueChanged( double ) ), this, SLOT( updateTheta( double ) ) );
    QObject::connect(
        alpha_, SIGNAL( valueChanged( double ) ), this, SLOT( updateAlpha( double ) ) );
}

void PhyDirectionControllerWidget::setDirectionController(
    VectorControllerAdapterWeakPtr directionControllerWeak )
{
    directionControllerWeak_ = directionControllerWeak;
    if ( auto directionController = directionControllerWeak_.lock() )
    {
        const phycoub::Vector coordinate = directionController->getValue();
        thetaGrad_ = calculateTheta( coordinate );
        alphaGrad_ = calculateAlpha( coordinate );

        theta_->setValue( thetaGrad_ );
        alpha_->setValue( alphaGrad_ );
    }
}

void PhyDirectionControllerWidget::updateTheta( double value )
{
    thetaGrad_ = value;
    theta_->setValue( thetaGrad_ );
    updateDirectionController();
}

void PhyDirectionControllerWidget::updateAlpha( double value )
{
    alphaGrad_ = value;
    alpha_->setValue( alphaGrad_ );
    updateDirectionController();
}

void PhyDirectionControllerWidget::configureSpinBox()
{
    theta_->setRange( 0, 180 );
    theta_->setDecimals( 1 );
    theta_->setSingleStep( 0.1 );

    thetaLayout_->addWidget( thetaLabel_ );
    thetaLayout_->addWidget( theta_ );

    alpha_->setRange( 0, 360 );
    alpha_->setDecimals( 1 );
    alpha_->setSingleStep( 0.1 );

    alphaLayout_->addWidget( alphaLabel_ );
    alphaLayout_->addWidget( alpha_ );
}

void PhyDirectionControllerWidget::updateDirectionController()
{
    if ( auto directionController = directionControllerWeak_.lock() )
    {
        auto direction = sphereToDirectionCoordinate( thetaGrad_, alphaGrad_ );
        directionController->setValue( direction );
    }
}

// static
double PhyDirectionControllerWidget::calculateTheta( const phycoub::Vector& direction )
{
    return ( direction.z() == 0
                   ? std::signbit( direction.z() ) ? -M_PI / 2 : M_PI / 2
                   : atan( sqrt( pow( direction.x(), 2 ) + pow( direction.y(), 2 ) )
                       / direction.z() ) )
        * radianToGrad_;
}

// static
double PhyDirectionControllerWidget::calculateAlpha( const phycoub::Vector& direction )
{
    return ( direction.x() == 0
                   ? std::signbit( direction.y() * direction.x() ) ? -M_PI / 2 : M_PI / 2
                   : atan( direction.y() / direction.x() ) )
        * radianToGrad_;
}

// static
phycoub::Vector PhyDirectionControllerWidget::sphereToDirectionCoordinate(
    double theta, double alpha )
{
    const double thetaRad = theta / radianToGrad_;
    const double alphaRad = alpha / radianToGrad_;

    phycoub::Vector direction;
    direction.x() = sin( thetaRad ) * cos( alphaRad );
    direction.y() = sin( thetaRad ) * sin( alphaRad );
    direction.z() = cos( thetaRad );

    return direction;
}

} // namespace phywidgets
