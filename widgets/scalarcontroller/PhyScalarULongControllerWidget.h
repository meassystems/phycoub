#ifndef PHYSCALARLONGCONTROLLERWIDGET_H
#define PHYSCALARLONGCONTROLLERWIDGET_H

#include "PhyScalarControllerWidgetBase.h"

namespace phywidgets
{

class PhyScalarULongControllerWidget : public PhyScalarControllerWidgetBase< long >
{
    Q_OBJECT

  public:
    explicit PhyScalarULongControllerWidget( QWidget* parent = nullptr );
    virtual ~PhyScalarULongControllerWidget() override = default;

  private slots:
    void onSetScalarValueClicked();

  private:
    void setValidator();
};

} // namespace phywidgets

#endif // PHYSCALARLONGCONTROLLERWIDGET_H
