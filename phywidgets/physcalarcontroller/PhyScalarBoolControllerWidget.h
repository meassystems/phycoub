#ifndef PHYSCALARBOOLCONTROLLERWIDGET_H
#define PHYSCALARBOOLCONTROLLERWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QPushButton>

#include "ValueControllerAdapterIface.h"
#include "PhyCoubControllerSubscriberIface.h"
#include "PhyBoolPhyCoubControllerSubscriber.h"

namespace phywidgets
{

class PhyScalarBoolControllerWidget : public QWidget
{
    Q_OBJECT
  public:
    explicit PhyScalarBoolControllerWidget( QWidget* parent = nullptr );
    virtual ~PhyScalarBoolControllerWidget();

    void setScalarController( BoolControllerAdapterWeakPtr boolControllerAdapterWeak );
    void setScalarValueLabel( const QString& scalarValueLabel );

    PhyCoubControllerSubscriberWeakPtr getPhyCoubControllerSubscriber();

  private slots:
    void onSetScalarValueClicked();

  protected:
    friend class PhyBoolPhyCoubControllerSubscriber;

  private:
    void configureBoolScalarVaule();

    BoolControllerAdapterWeakPtr boolControllerAdapterWeak_;
    PhyBoolPhyCoubControllerSubscriberPtr controllerSubscriber_ = nullptr;

    QHBoxLayout* scalarLayout_ = nullptr;
    QCheckBox* editScalarValue_ = nullptr;
    QPushButton* setScalarValueButton_ = nullptr;
};

} // namespace phywidgets

#endif // PHYSCALARBOOLCONTROLLERWIDGET_H
