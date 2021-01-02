#include "ModelViewerGLWidget.h"

#include <QGL>
#include <QtGui>

namespace phywidgets
{

ModelViewerGLWidget::ModelViewerGLWidget( QWidget* parent /* = nullptr*/ )
    : QGLWidget( QGLFormat( QGL::SampleBuffers ), parent )
    , phyCoubGL_( std::make_shared< PhyCoubGL >( this ) )
    , trajectoryControllerAdapter_(
          std::make_shared< TrajectoryScalarControllerAdapter >( phyCoubGL_ ) )
{
    QObject::connect( &timerPlot_, SIGNAL( timeout() ), this, SLOT( updateGL() ) );
    timerPlot_.start( 30 );
    gLRotationModelAdapter_ = std::make_shared< GLRotationModelAdapter >( this );
}

// virtual override
void ModelViewerGLWidget::updateGlRotation( int xRot, int yRot, int zRot )
{
    xRot_ = xRot;
    yRot_ = yRot;
    zRot_ = zRot;

    updateGL();
}

void ModelViewerGLWidget::setGetCoubSizeAdapter(
    GetCoubSizeAdapterWeakPtr getCoubSizeAdapter )
{
    phyCoubGL_->setGetCoubSizeAdapter( getCoubSizeAdapter );
    updateGL();
}

void ModelViewerGLWidget::setGetParticleForGLAdapter(
    GetParticlesAdapterWeakPtr getParticlesForGLAdapter )
{
    phyCoubGL_->setGetParticleForGLAdapter( getParticlesForGLAdapter );
    updateGL();
}

void ModelViewerGLWidget::setGLRotationController(
    GLRotationControllerWeakPtr gLRotationControllerWeak )
{
    gLRotationControllerWeak_ = gLRotationControllerWeak;
    if ( auto gLRotationController = gLRotationControllerWeak_.lock() )
    {
        gLRotationController->subscribeForUpdates( gLRotationModelAdapter_ );
    }
}

BoolControllerAdapterWeakPtr ModelViewerGLWidget::getTrajectoryControllerAdapter()
{
    return trajectoryControllerAdapter_;
}

PhyCoubControllerSubscriberWeakPtr ModelViewerGLWidget::getPhyCoubSubscriber()
{
    return phyCoubGL_;
}

void ModelViewerGLWidget::setXRotation( int angle )
{
    if ( auto gLRotationController = gLRotationControllerWeak_.lock() )
    {
        gLRotationController->updateRotationX( angle );
    }
}

void ModelViewerGLWidget::setYRotation( int angle )
{
    if ( auto gLRotationController = gLRotationControllerWeak_.lock() )
    {
        gLRotationController->updateRotationY( angle );
    }
}

void ModelViewerGLWidget::setZRotation( int angle )
{
    if ( auto gLRotationController = gLRotationControllerWeak_.lock() )
    {
        gLRotationController->updateRotationZ( angle );
    }
}

// virtual override
void ModelViewerGLWidget::initializeGL()
{
    qglClearColor( Qt::black );
}

// virtual override
void ModelViewerGLWidget::resizeGL( int width, int height )
{
    int side = qMin( width, height );
    glViewport( ( width - side ) / 2, ( height - side ) / 2, side, side );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
#ifdef QT_OPENGL_ES_1
    glOrthof( -0.5, +0.5, -0.5, +0.5, 4.0, 15.0 );
#else
    glOrtho( -0.5, +0.5, -0.5, +0.5, 4.0, 15.0 );
#endif
    glMatrixMode( GL_MODELVIEW );
}

// virtual override
void ModelViewerGLWidget::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();
    glTranslatef( 0.0, 0.0, -10.0 );

    glScaled( zoomScale_, zoomScale_, zoomScale_ );
    glRotatef( static_cast< float >( xRot_ / 16.0 ), 1.0, 0.0, 0.0 );
    glRotatef( static_cast< float >( yRot_ / 16.0 ), 0.0, 1.0, 0.0 );
    glRotatef( static_cast< float >( zRot_ / 16.0 ), 0.0, 0.0, 1.0 );

    phyCoubGL_->updateScene();
}

// virtual override
void ModelViewerGLWidget::mousePressEvent( QMouseEvent* event )
{
    lastPos_ = event->pos();
}

// virtual override
void ModelViewerGLWidget::mouseMoveEvent( QMouseEvent* event )
{
    int dx = event->x() - lastPos_.x();
    int dy = event->y() - lastPos_.y();

    if ( event->buttons() & Qt::LeftButton )
    {
        setXRotation( xRot_ + 8 * dy );
        setYRotation( yRot_ + 8 * dx );
    }
    else if ( event->buttons() & Qt::RightButton )
    {
        setXRotation( xRot_ + 8 * dy );
        setZRotation( zRot_ + 8 * dx );
    }
    lastPos_ = event->pos();
}

// virtual override
void ModelViewerGLWidget::wheelEvent( QWheelEvent* event )
{
    QPoint numDegrees = event->angleDelta();
    if ( numDegrees.y() < 0 )
    {
        zoomScale_ = zoomScale_ / 1.1;
    }
    if ( numDegrees.y() > 0 )
    {
        zoomScale_ = zoomScale_ * 1.1;
    }
    updateGL();
}

} // namespace phywidgets
