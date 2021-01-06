#ifndef PHYDIRECTIONGLCONTROLLER_H
#define PHYDIRECTIONGLCONTROLLER_H

#include <QGLWidget>
#include <QTimer>

#include "GLRotationController.h"
#include "GLRotationDirectionViewAdapter.h"
#include "GLRotationIface.h"
#include "ValueControllerAdapterIface.h"
#include "Vector.h"

namespace phywidgets
{

class PhyDirectionGLWidget
    : public QGLWidget
    , public GLRotationIface
{
  public:
    PhyDirectionGLWidget( QWidget* parent = nullptr );

    // Implementation of GLRotationIface
    virtual void updateGlRotation( int xRot, int yRot, int zRot ) override;

    void setColor( QColor color );

    void setGLRotattionController( GLRotationControllerWeakPtr gLRotationControllerWeak );
    void setDirectionController( VectorControllerAdapterWeakPtr directionControllerWeak );

  public slots:
    void setXRotation( int angle );
    void setYRotation( int angle );
    void setZRotation( int angle );

  protected:
    friend class GLRotationDirectionViewAdapter;

    virtual void initializeGL() override;
    virtual void resizeGL( int width, int height ) override;
    virtual void paintGL() override;

    virtual void mousePressEvent( QMouseEvent* event ) override;
    virtual void mouseMoveEvent( QMouseEvent* event ) override;

  private:
    void drawCoordinateSystem();
    void drawDirectionVector();

    GLRotationControllerWeakPtr gLRotationControllerWeak_;
    VectorControllerAdapterWeakPtr directionControllerWeak_;
    std::shared_ptr< GLRotationDirectionViewAdapter > gLRotationDirectionViewAdapter_
        = nullptr;

    int xRot_ = 0;
    int yRot_ = 0;
    int zRot_ = 0;

    double zoomScale_ = 0.4;
    QPoint lastPos_;
    QTimer timerPlot_;

    QColor _color = Qt::cyan;
};

} // namespace phywidgets

#endif // PHYDIRECTIONGLCONTROLLER_H
