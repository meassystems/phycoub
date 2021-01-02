#ifndef PHYVIEWPARTICLETABLEWIDGET_H
#define PHYVIEWPARTICLETABLEWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QTimer>
#include <QLineEdit>
#include <QPushButton>

#include "GetParticlesAdapterIface.h"
#include "GetCoubSizeAdapterIface.h"

namespace phywidgets
{

class PhyViewParticleTableWidget : public QWidget
{
    Q_OBJECT
  public:
    explicit PhyViewParticleTableWidget( QWidget* parent = nullptr );

    void setGetParticleAdapter( GetParticlesAdapterWeakPtr getParticlesForGLAdapter );
    void setGetCoubSizeAdapter( GetCoubSizeAdapterWeakPtr getCoubSizeAdapter );

  private slots:
    void updateParticleTable();

  private:
    void initializeTableWidget();

    GetParticlesAdapterWeakPtr getParticlesAdapterWeak_;
    GetCoubSizeAdapterWeakPtr getCoubSizeAdapterWeak_;

    QTimer timerPlot_;

    QVBoxLayout* layout_ = nullptr;
    QTableWidget* tableWidget_ = nullptr;
};

} // namespace phywidgets

#endif // PHYVIEWPARTICLETABLEWIDGET_H
