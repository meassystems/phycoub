#include "PhyHomogeneousDirectFieldControllerWidget.h"

namespace phywidgets
{

PhyHomogeneousDirectFieldControllerWidget::PhyHomogeneousDirectFieldControllerWidget(
    QWidget* parent )
    : QWidget( parent )
    , layout_( new QVBoxLayout( this ) )
    , aligmentGroupLayout_( new QVBoxLayout( this ) )
    , alignmentGroup_( new QGroupBox( this ) )
    , aligmentGlLayout_( new QHBoxLayout( this ) )
    , alignmentGl_( new QGroupBox( tr( "Вектор поля" ), this ) )
    , directionViewerGLWidget_( new PhyDirectionGLWidget( this ) )
    , homogeneousFieldControllerWidget_( new HomogeneousFieldControllerWidget( this ) )
{

    setLayout( layout_ );
    layout_->addWidget( alignmentGroup_ );
    alignmentGroup_->setLayout( aligmentGroupLayout_ );

    alignmentGl_->setLayout( aligmentGlLayout_ );
    aligmentGlLayout_->addWidget( directionViewerGLWidget_ );

    aligmentGroupLayout_->addWidget( alignmentGl_ );
    aligmentGroupLayout_->addWidget( homogeneousFieldControllerWidget_ );

    QSizePolicy viewPolicy = alignmentGl_->sizePolicy();
    viewPolicy.setVerticalStretch( 5 );
    alignmentGl_->setSizePolicy( viewPolicy );

    QSizePolicy controlPolicy = homogeneousFieldControllerWidget_->sizePolicy();
    controlPolicy.setVerticalStretch( 1 );
    homogeneousFieldControllerWidget_->setSizePolicy( controlPolicy );
}

void PhyHomogeneousDirectFieldControllerWidget::setGLRotattionController(
    GLRotationControllerWeakPtr gLRotationControllerWeak )

{
    directionViewerGLWidget_->setGLRotattionController( gLRotationControllerWeak );
}

void PhyHomogeneousDirectFieldControllerWidget::setDirectionController(
    VectorControllerAdapterWeakPtr directionControllerWeak )
{
    directionViewerGLWidget_->setDirectionController( directionControllerWeak );
    homogeneousFieldControllerWidget_->setDirectionController( directionControllerWeak );
}

void PhyHomogeneousDirectFieldControllerWidget::setScalarController(
    DoubleControllerAdapterWeakPtr scalarControllerWeak )
{
    homogeneousFieldControllerWidget_->setScalarController( scalarControllerWeak );
}

void PhyHomogeneousDirectFieldControllerWidget::setHeader( const QString& header )
{
    alignmentGroup_->setTitle( header );
}

void PhyHomogeneousDirectFieldControllerWidget::setScalarValueLabel(
    const QString& scalarValueLabel )
{
    homogeneousFieldControllerWidget_->setScalarValueLabel( scalarValueLabel );
}

} // namespace phywidgets
