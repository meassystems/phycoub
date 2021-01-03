#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QAction>

MainWindow::MainWindow( QWidget* parent )
    : QMainWindow( parent )
    , ui( new Ui::MainWindow )
{
    ui->setupUi( this );
    setWindowTitle( tr( "Магнетрон" ) );

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
    magnetronController_ = std::make_shared< MagnetronController >();

    ui->radiusScalar->setScalarValueLabel( "Радиус магнитрона" );
    ui->heightScalar->setScalarValueLabel( "Высота магнитрона" );
    ui->electricScalar->setScalarValueLabel( "Электрическое поле" );
    ui->magneticScalar->setScalarValueLabel( "Магнитная индукция" );
    ui->energyScalar->setScalarValueLabel( "Энергия рождения" );
    ui->lifeParticleCountScalar->setScalarValueLabel( "Плотность частиц" );
    ui->trajectory->setScalarValueLabel( "Траектория" );

    if ( auto phyCoubController = magnetronController_->getPhyCoubController().lock() )
    {
        ui->phyCoubController->setPhyCoubController( phyCoubController );
        phyCoubController->subscribe(
            ui->radiusScalar->getPhyCoubControllerSubscriber() );
        phyCoubController->subscribe(
            ui->heightScalar->getPhyCoubControllerSubscriber() );
        phyCoubController->subscribe( ui->coubGL->getPhyCoubSubscriber() );
    }
    else
    {
        throw std::logic_error{ "PhyCoubController must exist's" };
    }

    ui->coubGL->setGLRotationController(
        magnetronController_->getGLRotationController() );
    ui->coubGL->setGetCoubSizeAdapter( magnetronController_ );
    ui->coubGL->setGetParticleForGLAdapter(
        magnetronController_->getGetParticleForGLAdapter() );

    ui->radiusScalar->setScalarController(
        magnetronController_->getRadiusScalarControllerAdapter() );
    ui->heightScalar->setScalarController(
        magnetronController_->getHeightScalarControllerAdapter() );
    ui->electricScalar->setScalarController(
        magnetronController_->getElectricScalarControllerAdapter() );
    ui->magneticScalar->setScalarController(
        magnetronController_->getMagneticScalarControllerAdapter() );
    ui->energyScalar->setScalarController(
        magnetronController_->getEnergyScalarControllerAdapter() );
    ui->lifeParticleCountScalar->setScalarController(
        magnetronController_->getLifeParticleCountScalarControllerAdapter() );
    ui->trajectory->setScalarController( ui->coubGL->getTrajectoryControllerAdapter() );
}

void MainWindow::configureMenu()
{
    QAction* restart = new QAction( tr( "Перезапустить" ), this );
    QObject::connect( restart, SIGNAL( triggered() ), this, SLOT( restart() ) );

    menu = ui->menubar->addMenu( tr( "Меню" ) );
    menu->addAction( restart );
}
