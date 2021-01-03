#include "WidgetConfigurationUtils.h"

#include <exception>
#include <QVBoxLayout>
#include <QGroupBox>

#include "PhyDirectionGLWidget.h"
#include "PhyDirectionControllerWidget.h"
#include "PhyScalarDoubleControllerWidget.h"

namespace phywilsoncloudchamber
{

void WidgetConfigurationUtils::initializeParticleSourceWidget( QWidget* widget,
    GLRotationControllerWeakPtr gLRotationControllerWeak,
    VectorControllerAdapterWeakPtr directionControllerAdapter,
    DoubleControllerAdapterWeakPtr angleControllerAdapter,
    DoubleControllerAdapterWeakPtr bornPeriodControllerAdapter,
    DoubleControllerAdapterWeakPtr bornEnergyControllerAdapter, QString sourceName )
{
    if ( !widget )
    {
        throw std::invalid_argument( "NotInitialized WidgetPtr" );
    }

    QLayout* layout = widget->layout();
    layout = layout ? layout : new QVBoxLayout( widget );
    widget->setLayout( layout );

    QGroupBox* mainBox = new QGroupBox( widget );
    QVBoxLayout* mainBoxLayout = new QVBoxLayout( widget );
    mainBox->setLayout( mainBoxLayout );
    layout->addWidget( mainBox );
    mainBox->setTitle( sourceName );

    PhyDirectionGLWidget* directionGlWidget = new PhyDirectionGLWidget( widget );
    directionGlWidget->setGLRotattionController( gLRotationControllerWeak );
    directionGlWidget->setDirectionController( directionControllerAdapter );
    mainBoxLayout->addWidget( directionGlWidget );

    QSizePolicy glSizePolicy = directionGlWidget->sizePolicy();
    glSizePolicy.setVerticalStretch( 5 );
    directionGlWidget->setSizePolicy( glSizePolicy );

    QGroupBox* confixBox = new QGroupBox( widget );
    QVBoxLayout* confixBoxLayout = new QVBoxLayout( widget );
    confixBox->setLayout( confixBoxLayout );
    mainBoxLayout->addWidget( confixBox );

    QSizePolicy configSizePolicy = confixBox->sizePolicy();
    configSizePolicy.setVerticalStretch( 3 );
    confixBox->setSizePolicy( configSizePolicy );

    PhyDirectionControllerWidget* directionControllerWidget
        = new PhyDirectionControllerWidget( widget );
    directionControllerWidget->setDirectionController( directionControllerAdapter );
    confixBoxLayout->addWidget( directionControllerWidget );

    PhyScalarDoubleControllerWidget* angleControllerWidget
        = new PhyScalarDoubleControllerWidget( widget );
    angleControllerWidget->setScalarController( angleControllerAdapter );
    confixBoxLayout->addWidget( angleControllerWidget );
    angleControllerWidget->setScalarValueLabel( "Угол разлета, [рад]" );

    PhyScalarDoubleControllerWidget* bornPeriodControllerWidget
        = new PhyScalarDoubleControllerWidget( widget );
    bornPeriodControllerWidget->setScalarController( bornPeriodControllerAdapter );
    confixBoxLayout->addWidget( bornPeriodControllerWidget );
    bornPeriodControllerWidget->setScalarValueLabel( "Период рождения, [c]" );

    PhyScalarDoubleControllerWidget* bornEnergyControllerWidget
        = new PhyScalarDoubleControllerWidget( widget );
    bornEnergyControllerWidget->setScalarController( bornEnergyControllerAdapter );
    confixBoxLayout->addWidget( bornEnergyControllerWidget );
    bornEnergyControllerWidget->setScalarValueLabel( "Энергия рождения, [Дж]" );
}

} // namespace phywilsoncloudchamber
