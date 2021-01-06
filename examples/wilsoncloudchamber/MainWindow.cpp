#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "WidgetConfigurationUtils.h"

MainWindow::MainWindow( QWidget* parent )
    : QMainWindow( parent )
    , ui( new Ui::MainWindow )
{
    ui->setupUi( this );
    setWindowTitle( tr( "Камера Вильсона" ) );

    configureMenu();
    startNewMagnetron();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::restart()
{
    startNewMagnetron();
}

void MainWindow::startNewMagnetron()
{
    coubController_ = std::make_shared< WilsonCloudChamberController >();

    ui->sizeController->setScalarValueLabel( "Размер куба" );
    ui->trajectoryController->setScalarValueLabel( "Траектория" );

    if ( auto phyCoubController = coubController_->getPhyCoubController().lock() )
    {
        ui->phyCoubController->setPhyCoubController( phyCoubController );

        phyCoubController->subscribe( ui->coubGL->getPhyCoubSubscriber() );
        phyCoubController->subscribe(
            ui->sizeController->getPhyCoubControllerSubscriber() );
    }
    else
    {
        throw std::logic_error{ "PhyCoubController must exist's" };
    }

    ui->coubGL->setGLRotationController( coubController_->getGLRotationController() );
    ui->coubGL->setGetCoubSizeAdapter( coubController_ );
    ui->coubGL->setGetParticleForGLAdapter(
        coubController_->getGetParticleForGLAdapter() );

    ui->electricFieldController->setGLRotattionController(
        coubController_->getGLRotationController() );
    ui->electricFieldController->setDirectionController(
        coubController_->getElectricDirectionControllerAdapter() );
    ui->electricFieldController->setScalarController(
        coubController_->getElectricScalarControllerAdapter() );
    ui->electricFieldController->setHeader( tr( "Электрическое поле" ) );
    ui->electricFieldController->setScalarValueLabel( tr( "q, [Кл]" ) );

    ui->electricFieldController->setColor( Qt::cyan );
    ui->coubGL->addDrawInCube( ui->electricFieldController->getDrawInCube() );

    ui->magneticFieldController->setGLRotattionController(
        coubController_->getGLRotationController() );
    ui->magneticFieldController->setDirectionController(
        coubController_->getMagneticDirectionControllerAdapter() );
    ui->magneticFieldController->setScalarController(
        coubController_->getMagneticScalarControllerAdapter() );
    ui->magneticFieldController->setHeader( tr( "Магнитное поле" ) );
    ui->magneticFieldController->setScalarValueLabel( tr( "B, [Тл]" ) );

    ui->magneticFieldController->setColor( Qt::magenta );
    ui->coubGL->addDrawInCube( ui->magneticFieldController->getDrawInCube() );

    ui->sizeController->setScalarController(
        coubController_->getSizeScalarControllerAdapter() );
    ui->trajectoryController->setScalarController(
        ui->coubGL->getTrajectoryControllerAdapter() );

    ui->particleTable->setGetParticleAdapter(
        coubController_->getGetParticleForGLAdapter() );
    ui->particleTable->setGetCoubSizeAdapter( coubController_ );

    WidgetConfigurationUtils::initializeParticleSourceWidget( ui->electron_source,
        coubController_->getGLRotationController(),
        coubController_->getElectronSourceDirectionScalarControllerAdapter(),
        coubController_->getElectronSourceAngleControllerAdapter(),
        coubController_->getElectronSourceBornPeriodControllerAdapter(),
        coubController_->getElectronSourceBornEnergyControllerAdapter(),
        "Источник электронов" );
    WidgetConfigurationUtils::initializeParticleSourceWidget( ui->proton_source,
        coubController_->getGLRotationController(),
        coubController_->getProtonSourceDirectionScalarControllerAdapter(),
        coubController_->getProtonSourceAngleControllerAdapter(),
        coubController_->getProtonSourceBornPeriodControllerAdapter(),
        coubController_->getProtonSourceBornEnergyControllerAdapter(),
        "Источник протонов" );
    WidgetConfigurationUtils::initializeParticleSourceWidget( ui->specific_source,
        coubController_->getGLRotationController(),
        coubController_->getSpecificSourceDirectionScalarControllerAdapter(),
        coubController_->getSpecificSourceAngleControllerAdapter(),
        coubController_->getSpecificSourceBornPeriodControllerAdapter(),
        coubController_->getSpecificSourceBornEnergyControllerAdapter(),
        "Источник специфичных частиц" );

    ui->specificParticleOptionsController->setParticleOptionsControllerAdapter(
        coubController_->getSpecificSourceParticleOptionsControllerAdapter() );
    ui->specificParticleOptionsController->setTitle( tr( "Свойства ваших частиц" ) );
}

void MainWindow::configureMenu()
{
    QAction* restart = new QAction( tr( "Перезапустить" ), this );
    QObject::connect( restart, SIGNAL( triggered() ), this, SLOT( restart() ) );

    menu = ui->menubar->addMenu( tr( "Меню" ) );
    menu->addAction( restart );
}
