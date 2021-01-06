#ifndef MODELVIEWERGLWIDGET_H
#define MODELVIEWERGLWIDGET_H

#include <QGLWidget>
#include <QTimer>
#include <list>

#include "PhyCoubGL.h"
#include "GLRotationController.h"
#include "GLRotationModelAdapter.h"
#include "ValueControllerAdapterIface.h"
#include "PhyCoubGlScalarControllerAdapters.h"
#include "PhyCoubControllerSubscriberIface.h"
#include "DrawInCubeGlIface.h"

namespace phywidgets
{

class ModelViewerGLWidget final
    : public QGLWidget
    , public GLRotationIface
{
  public:
    explicit ModelViewerGLWidget( QWidget* parent = nullptr );
    virtual ~ModelViewerGLWidget() override = default;

    // Implementation of GLRotationIface
    virtual void updateGlRotation( int xRot, int yRot, int zRot ) override;

    void addDrawInCube(DrawInCubeGlPtr drawInCube);

    void setGetCoubSizeAdapter( GetCoubSizeAdapterWeakPtr getCoubSizeAdapter );
    void setGetParticleForGLAdapter(
        GetParticlesAdapterWeakPtr getParticlesForGLAdapter );
    void setGLRotationController( GLRotationControllerWeakPtr gLRotationControllerWeak );

    BoolControllerAdapterWeakPtr getTrajectoryControllerAdapter();
    PhyCoubControllerSubscriberWeakPtr getPhyCoubSubscriber();

  public slots:
    void setXRotation( int angle );
    void setYRotation( int angle );
    void setZRotation( int angle );

  protected:
    friend class GLRotationModelAdapter;

    virtual void initializeGL() override;
    virtual void resizeGL( int width, int height ) override;
    virtual void paintGL() override;

    virtual void mousePressEvent( QMouseEvent* event ) override;
    virtual void mouseMoveEvent( QMouseEvent* event ) override;
    virtual void wheelEvent( QWheelEvent* event ) override;

  private:
    int xRot_ = 0;
    int yRot_ = 0;
    int zRot_ = 0;
    double zoomScale_ = 0.7;

    PhyCoubGLPtr phyCoubGL_;
    TrajectoryScalarControllerAdapterPtr trajectoryControllerAdapter_;

    std::list<DrawInCubeGlWeak> drawInCubeList;

    GLRotationControllerWeakPtr gLRotationControllerWeak_;
    std::shared_ptr< GLRotationModelAdapter > gLRotationModelAdapter_ = nullptr;

    QPoint lastPos_;
    QTimer timerPlot_;
};

} // namespace phywidgets

#endif // MODELVIEWERGLWIDGET_H
