#include "PhyScalarDoubleControllerWidget.h"

#include <QDoubleValidator>

namespace phywidgets
{

PhyScalarDoubleControllerWidget::PhyScalarDoubleControllerWidget( QWidget* parent )
    : PhyScalarControllerWidgetBase( parent )
{
    setValidator();

    QObject::connect( setScalarValueButton_, SIGNAL( clicked() ), this,
        SLOT( onSetScalarValueClicked() ) );
}

void PhyScalarDoubleControllerWidget::onSetScalarValueClicked()
{

    if ( auto scalarConrollerAdapter = getScalarControllerAdapter().lock() )
    {
        scalarConrollerAdapter->setValue( getValueEdit()->text().toDouble() );
    }
}

void PhyScalarDoubleControllerWidget::setValidator()
{
    const QDoubleValidator* scalarValidator
        = new QDoubleValidator{ -3'000'000'000., 3'000'000'000., 2, this };

    auto* valueEdit = getValueEdit();
    valueEdit->setValidator( scalarValidator );
}

} // namespace phywidgets
