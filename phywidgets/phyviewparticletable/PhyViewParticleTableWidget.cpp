#include "PhyViewParticleTableWidget.h"

#include <QHeaderView>

namespace phywidgets
{

PhyViewParticleTableWidget::PhyViewParticleTableWidget( QWidget* parent /* = nullptr*/ )
    : QWidget( parent )
    , layout_( new QVBoxLayout( this ) )
    , tableWidget_( new QTableWidget( this ) )
{
    initializeTableWidget();

    setLayout( layout_ );
    layout_->addWidget( tableWidget_ );

    QObject::connect(
        &timerPlot_, SIGNAL( timeout() ), this, SLOT( updateParticleTable() ) );

    timerPlot_.start( 100 );
}

void PhyViewParticleTableWidget::setGetParticleAdapter(
    GetParticlesAdapterWeakPtr getParticlesForGLAdapter )
{
    getParticlesAdapterWeak_ = getParticlesForGLAdapter;
}

void PhyViewParticleTableWidget::setGetCoubSizeAdapter(
    GetCoubSizeAdapterWeakPtr getCoubSizeAdapter )
{
    getCoubSizeAdapterWeak_ = getCoubSizeAdapter;
}

void PhyViewParticleTableWidget::updateParticleTable()
{
    using namespace phycoub;

    if ( auto getParticlesAdapter = getParticlesAdapterWeak_.lock() )
        if ( auto getCoubSizeAdapter = getCoubSizeAdapterWeak_.lock() )
        {
            {
                const Vector& coubSize = getCoubSizeAdapter->getCoubSize();

                const ParticleGroupList particleGroupList
                    = getParticlesAdapter->getParticles();

                tableWidget_->setRowCount(
                    static_cast< int >( particleGroupList.getParticleCount() ) );

                int rowIndex = 0;
                particleGroupList.forEachParticle( [this, &rowIndex, coubSize](
                                                       ParticlePtr particle ) {
                    tableWidget_->setItem( rowIndex, 0,
                        new QTableWidgetItem( QString::number( particle->getId() ) ) );

                    const Vector& coordinate = particle->getCoordinate();
                    tableWidget_->setItem( rowIndex, 1,
                        new QTableWidgetItem(
                            QString::number( coordinate.x_ / coubSize.x_ ) ) );
                    tableWidget_->setItem( rowIndex, 2,
                        new QTableWidgetItem(
                            QString::number( coordinate.y_ / coubSize.y_ ) ) );
                    tableWidget_->setItem( rowIndex, 3,
                        new QTableWidgetItem(
                            QString::number( coordinate.z_ / coubSize.z_ ) ) );

                    const Vector& speed = particle->getSpeed();
                    tableWidget_->setItem( rowIndex, 4,
                        new QTableWidgetItem( QString::number( speed.x_ ) ) );
                    tableWidget_->setItem( rowIndex, 5,
                        new QTableWidgetItem( QString::number( speed.y_ ) ) );
                    tableWidget_->setItem( rowIndex, 6,
                        new QTableWidgetItem( QString::number( speed.z_ ) ) );

                    const ParticleOptions options = particle->getOptions();
                    tableWidget_->setItem( rowIndex, 7,
                        new QTableWidgetItem( QString::number( options.m_ ) ) );
                    tableWidget_->setItem( rowIndex, 8,
                        new QTableWidgetItem( QString::number( options.q_ ) ) );

                    ++rowIndex;
                } );
            }
        }
}

void PhyViewParticleTableWidget::initializeTableWidget()
{
    static const QStringList headers = { tr( "Идентификатор" ), tr( "Координата X" ),
        tr( "Координата Y" ), tr( "Координата Z" ), tr( "Пр. скорости X [м/c]" ),
        tr( "Пр. скорости Y [м/c]" ), tr( "Пр. скорости Z [м/c]" ), tr( "Масса [кг]" ),
        tr( "Заряд [Кл]" ) };

    tableWidget_->setColumnCount( headers.size() );
    tableWidget_->setHorizontalHeaderLabels( headers );

    tableWidget_->setEditTriggers( QAbstractItemView::NoEditTriggers );
    tableWidget_->horizontalHeader()->setStretchLastSection( true );
    tableWidget_->verticalHeader()->hide();

    tableWidget_->setSelectionMode( QAbstractItemView::SingleSelection );
    tableWidget_->setSelectionBehavior( QAbstractItemView::SelectRows );
}

} // namespace phywidgets
