#ifndef HOMOGENIUSFIELDCONTROLLERWIDGET_H
#define HOMOGENIUSFIELDCONTROLLERWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QGroupBox>

#include "ValueControllerAdapterIface.h"
#include "PhyDirectionControllerWidget.h"

namespace phywidgets
{

class HomogeneousFieldControllerWidget : public QWidget
{
    Q_OBJECT
  public:
    explicit HomogeneousFieldControllerWidget( QWidget* parent = nullptr );

    void setDirectionController( VectorControllerAdapterWeakPtr directionControllerWeak );
    void setScalarController( DoubleControllerAdapterWeakPtr scalarControllerWeak );

    void setScalarValueLabel( const QString& scalarValueLabel );

  private slots:
    void updateScalarValue( const QString& value );

  private:
    void configureScalarVaule();

    QHBoxLayout* layout_ = nullptr;

    QHBoxLayout* aligmentGroupLayout_ = nullptr;
    QGroupBox* alignmentGroup_ = nullptr;

    QVBoxLayout* scalarLayout_ = nullptr;
    QLabel* scalarLabel_ = nullptr;
    QLineEdit* scalarValueEdit_ = nullptr;
    PhyDirectionControllerWidget* directionControllerWidget_ = nullptr;

    VectorControllerAdapterWeakPtr directionControllerWeak_;
    DoubleControllerAdapterWeakPtr scalarControllerWeak_;
};

} // namespace phywidgets

#endif // HOMOGENIUSFIELDCONTROLLERWIDGET_H
