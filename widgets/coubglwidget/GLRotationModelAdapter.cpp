#include "GLRotationModelAdapter.h"

#include "ModelViewerGLWidget.h"

namespace phywidgets
{

GLRotationModelAdapter::GLRotationModelAdapter( ModelViewerGLWidget* widget )
    : widget_( widget )
{
}

GLRotationModelAdapter::~GLRotationModelAdapter()
{
    release();
}

// virtual override
void GLRotationModelAdapter::updateGlRotation( int xRot, int yRot, int zRot )
{
    std::lock_guard< std::mutex > lockGuard( widgetMutex_ );

    widget_->xRot_ = xRot;
    widget_->yRot_ = yRot;
    widget_->zRot_ = zRot;

    widget_->updateGL();
}

void GLRotationModelAdapter::release()
{
    std::lock_guard< std::mutex > lockGuard( widgetMutex_ );
    widget_ = nullptr;
}

} // namespace phywidgets
