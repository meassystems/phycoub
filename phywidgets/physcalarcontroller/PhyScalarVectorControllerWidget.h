#ifndef PHYSCALARVECTORCONTROLLERWIDGET_H
#define PHYSCALARVECTORCONTROLLERWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "ValueControllerAdapterIface.h"
#include "PhyCoubControllerSubscriberIface.h"
#include "PhyVectorPhyCoubControllerSubscriber.h"

namespace phywidgets
{

class PhyScalarVectorControllerWidget : public QWidget
{
    Q_OBJECT
  public:
    explicit PhyScalarVectorControllerWidget( QWidget* parent = nullptr );
    virtual ~PhyScalarVectorControllerWidget();

    void setScalarController(
        VectorControllerAdapterWeakPtr vectorControllerAdapterWeak );
    void setScalarValueLabel( const QString& scalarValueLabel );

    PhyCoubControllerSubscriberWeakPtr getPhyCoubControllerSubscriber();

  private slots:
    void onSetScalarValueClicked();

  protected:
    friend class PhyVectorPhyCoubControllerSubscriber;

  private:
    void configureVectorScalarVaule();

    VectorControllerAdapterWeakPtr vectorControllerAdapterWeak_;
    PhyVectorPhyCoubControllerSubscriberPtr controllerSubscriber_ = nullptr;

    QHBoxLayout* scalarLayout_ = nullptr;

    QVBoxLayout* editWithLabelLayout_ = nullptr;
    QLabel* editLabel_ = nullptr;
    QHBoxLayout* vectorEditLayout_ = nullptr;

    QVBoxLayout* xEditWithLabelLayout_ = nullptr;
    QLabel* xLabel_ = nullptr;
    QLineEdit* xEdit_ = nullptr;

    QVBoxLayout* yEditWithLabelLayout_ = nullptr;
    QLabel* yLabel_ = nullptr;
    QLineEdit* yEdit_ = nullptr;

    QVBoxLayout* zEditWithLabelLayout_ = nullptr;
    QLabel* zLabel_ = nullptr;
    QLineEdit* zEdit_ = nullptr;

    QPushButton* setScalarValueButton_ = nullptr;
};

} // namespace phywidgets

#endif // PHYSCALARVECTORCONTROLLERWIDGET_H
