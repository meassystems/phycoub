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
        auto decart = sphereToDecartCoordinate( thetaGrad_, alphaGrad_ );
        directionController->setValue( decart );
    }
}

// static
double PhyDirectionControllerWidget::calculateTheta( const phycoub::Vector& direction )
{
    return atan( sqrt( pow( direction.x_, 2 ) + pow( direction.y_, 2 ) ) / direction.z_ )
        * radianToGrad_;
}

// static
double PhyDirectionControllerWidget::calculateAlpha( const phycoub::Vector& direction )
{
    return atan( direction.y_ / direction.x_ ) * radianToGrad_;
}

// static
phycoub::Vector PhyDirectionControllerWidget::sphereToDecartCoordinate(
    double theta, double alpha )
{
    const double thetaRad = theta / radianToGrad_;
    const double alphaRad = alpha / radianToGrad_;

    phycoub::Vector decart;
    decart.x_ = sin( thetaRad ) * cos( alphaRad );
    decart.y_ = sin( thetaRad ) * sin( alphaRad );
    decart.z_ = cos( thetaRad );

    return decart;
}

} // namespace phywidgets
