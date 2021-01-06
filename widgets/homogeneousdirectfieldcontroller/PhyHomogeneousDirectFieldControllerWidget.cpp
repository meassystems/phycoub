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
    , _homogeneousFieldInCubeGl( new HomogeneousFieldInCubeGL( nullptr ) )
    , scalarLayout_( new QHBoxLayout( this ) )
    , editScalarValue_( new QCheckBox( this ) )
    , setScalarValueButton_( new QPushButton( this ) )
{

    setLayout( layout_ );
    layout_->addWidget( alignmentGroup_ );
    alignmentGroup_->setLayout( aligmentGroupLayout_ );

    alignmentGl_->setLayout( aligmentGlLayout_ );
    aligmentGlLayout_->addWidget( directionViewerGLWidget_ );

    aligmentGroupLayout_->addWidget( alignmentGl_ );
    aligmentGroupLayout_->addWidget( homogeneousFieldControllerWidget_ );

    configureShowFieldController();
    aligmentGroupLayout_->addLayout( scalarLayout_ );

    QSizePolicy viewPolicy = alignmentGl_->sizePolicy();
    viewPolicy.setVerticalStretch( 5 );
    alignmentGl_->setSizePolicy( viewPolicy );

    QSizePolicy controlPolicy = homogeneousFieldControllerWidget_->sizePolicy();
    controlPolicy.setVerticalStretch( 1 );
    homogeneousFieldControllerWidget_->setSizePolicy( controlPolicy );

    QObject::connect( setScalarValueButton_, SIGNAL( clicked() ), this,
                      SLOT( onSetScalarValueClicked() ) );
}

DrawInCubeGlPtr PhyHomogeneousDirectFieldControllerWidget::getDrawInCube() const
{
    return _homogeneousFieldInCubeGl;
}

void PhyHomogeneousDirectFieldControllerWidget::setColor( QColor color )
{
    directionViewerGLWidget_->setColor( color );
    _homogeneousFieldInCubeGl->setColor( color );
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
    _homogeneousFieldInCubeGl->setDirectionController( directionControllerWeak );
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

void PhyHomogeneousDirectFieldControllerWidget::onSetScalarValueClicked()
{
    _homogeneousFieldInCubeGl->setShowFlag( editScalarValue_->isChecked() );
}

void PhyHomogeneousDirectFieldControllerWidget::configureShowFieldController()
{
    scalarLayout_->addWidget( editScalarValue_ );
    scalarLayout_->addWidget( setScalarValueButton_ );

    editScalarValue_->setCheckState(
        _homogeneousFieldInCubeGl->isShow() ? Qt::Checked : Qt::Unchecked );

    editScalarValue_->setText( "Показать поле" );
    setScalarValueButton_->setText( "Установить" );
}

} // namespace phywidgets
