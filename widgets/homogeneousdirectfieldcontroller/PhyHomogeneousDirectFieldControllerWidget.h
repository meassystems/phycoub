#ifndef PHYHOMOGENEOUSDIRECTFIELDCONTROLLERWIDGET_H
#define PHYHOMOGENEOUSDIRECTFIELDCONTROLLERWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QPushButton>

#include "PhyDirectionGLWidget.h"
#include "HomogeneousFieldControllerWidget.h"
#include "HomogeneousFieldInCubeGL.h"
#include "DrawInCubeGlIface.h"
#include "GetCoubSizeAdapterIface.h"

namespace phywidgets
{

class PhyHomogeneousDirectFieldControllerWidget : public QWidget
{
    Q_OBJECT
  public:
    explicit PhyHomogeneousDirectFieldControllerWidget( QWidget* parent = nullptr );

    DrawInCubeGlPtr getDrawInCube() const;

    void setColor( QColor color );
    void setGLRotattionController( GLRotationControllerWeakPtr gLRotationControllerWeak );

    void setDirectionController( VectorControllerAdapterWeakPtr directionControllerWeak );
    void setScalarController( DoubleControllerAdapterWeakPtr scalarControllerWeak );

    void setHeader( const QString& header );
    void setScalarValueLabel( const QString& scalarValueLabel );

  private slots:
    void onSetScalarValueClicked();

  private:
    void configureShowFieldController();

    QVBoxLayout* layout_ = nullptr;

    QVBoxLayout* aligmentGroupLayout_ = nullptr;
    QGroupBox* alignmentGroup_ = nullptr;

    QHBoxLayout* aligmentGlLayout_ = nullptr;
    QGroupBox* alignmentGl_ = nullptr;

    PhyDirectionGLWidget* directionViewerGLWidget_ = nullptr;
    HomogeneousFieldControllerWidget* homogeneousFieldControllerWidget_ = nullptr;
    std::shared_ptr< HomogeneousFieldInCubeGL > _homogeneousFieldInCubeGl;

    QHBoxLayout* scalarLayout_ = nullptr;
    QCheckBox* editScalarValue_ = nullptr;
    QPushButton* setScalarValueButton_ = nullptr;
};

} // namespace phywidgets

#endif // PHYHOMOGENEOUSDIRECTFIELDCONTROLLERWIDGET_H
