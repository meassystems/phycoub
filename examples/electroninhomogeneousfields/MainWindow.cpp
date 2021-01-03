#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow( QWidget* parent )
    : QMainWindow( parent )
    , ui( new Ui::MainWindow )
{
    ui->setupUi( this );
    setWindowTitle( tr( "Электрон в электромагнитных полях" ) );

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
    coubController_ = std::make_shared< ElectronInHomogeneousFieldsController >();

    ui->sizeController->setScalarValueLabel( "Размер куба" );
    ui->e2eController->setScalarValueLabel( "Электрон-электрон взаимодействие" );
    ui->trajectoryController->setScalarValueLabel( "Траектория" );

    if ( auto phyCoubController = coubController_->getPhyCoubController().lock() )
    {
        ui->phyCoubController->setPhyCoubController( phyCoubController );

        phyCoubController->subscribe( ui->coubGL->getPhyCoubSubscriber() );
        phyCoubController->subscribe(
            ui->sizeController->getPhyCoubControllerSubscriber() );
        phyCoubController->subscribe( ui->addParticle->getPhyCoubSubsriber() );
        phyCoubController->subscribe( ui->removeParticle->getPhyCoubSubsriber() );
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

    ui->magneticFieldController->setGLRotattionController(
        coubController_->getGLRotationController() );
    ui->magneticFieldController->setDirectionController(
        coubController_->getMagneticDirectionControllerAdapter() );
    ui->magneticFieldController->setScalarController(
        coubController_->getMagneticScalarControllerAdapter() );
    ui->magneticFieldController->setHeader( tr( "Магнитное поле" ) );
    ui->magneticFieldController->setScalarValueLabel( tr( "B, [Тл]" ) );

    ui->sizeController->setScalarController(
        coubController_->getSizeScalarControllerAdapter() );
    ui->e2eController->setScalarController(
        coubController_->getE2EScalarControllerAdapter() );
    ui->trajectoryController->setScalarController(
        ui->coubGL->getTrajectoryControllerAdapter() );

    ui->particleTable->setGetParticleAdapter(
        coubController_->getGetParticleForGLAdapter() );
    ui->particleTable->setGetCoubSizeAdapter( coubController_ );

    const ParticleOptions defaultOptions{ phycoub::ElectricConstants::electronWeight,
        phycoub::ElectricConstants::electronCharge };

    ui->addParticle->setDefaultOptions( defaultOptions );
    ui->addParticle->setGetCoubSizeAdapter( coubController_ );
    ui->addParticle->setAddParticleControllerAdapter( coubController_ );

    ui->removeParticle->setRemoveParticleControllerAdapter( coubController_ );
}

void MainWindow::configureMenu()
{
    QAction* restart = new QAction( tr( "Перезапустить" ), this );
    QObject::connect( restart, SIGNAL( triggered() ), this, SLOT( restart() ) );

    menu = ui->menubar->addMenu( tr( "Меню" ) );
    menu->addAction( restart );
}
