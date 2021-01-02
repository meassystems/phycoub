#ifndef PHYSCALARCONTROLLER_H
#define PHYSCALARCONTROLLER_H

#include "PhyScalarControllerWidgetBase.h"

namespace phywidgets
{

class PhyScalarDoubleControllerWidget : public PhyScalarControllerWidgetBase< double >
{
    Q_OBJECT

  public:
    explicit PhyScalarDoubleControllerWidget( QWidget* parent = nullptr );
    virtual ~PhyScalarDoubleControllerWidget() override = default;

  private slots:
    void onSetScalarValueClicked();

  private:
    void setValidator();
};

} // namespace phywidgets

#endif // PHYSCALARCONTROLLER_H
