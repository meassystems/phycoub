#include "PhyScalarULongControllerWidget.h"

#include <QIntValidator>

namespace phywidgets
{

PhyScalarULongControllerWidget::PhyScalarULongControllerWidget( QWidget* parent )
    : PhyScalarControllerWidgetBase( parent )
{
    setValidator();

    QObject::connect( setScalarValueButton_, SIGNAL( clicked() ), this,
        SLOT( onSetScalarValueClicked() ) );
}

void PhyScalarULongControllerWidget::onSetScalarValueClicked()
{
    if ( auto scalarConrollerAdapter = getScalarControllerAdapter().lock() )
    {
        scalarConrollerAdapter->setValue( getValueEdit()->text().toLong() );
    }
}

void PhyScalarULongControllerWidget::setValidator()
{
    const QIntValidator* scalarValidator = new QIntValidator{ 0, 1'000'000, this };

    auto* valueEdit = getValueEdit();
    valueEdit->setValidator( scalarValidator );
}

} // namespace phywidgets
