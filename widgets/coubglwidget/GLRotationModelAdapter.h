#ifndef GLROTATIONMODELADAPTER_H
#define GLROTATIONMODELADAPTER_H

#include <mutex>

#include "GLRotationIface.h"

namespace phywidgets
{

class ModelViewerGLWidget;

class GLRotationModelAdapter final : public GLRotationIface
{
  public:
    GLRotationModelAdapter( ModelViewerGLWidget* widget );
    virtual ~GLRotationModelAdapter() override;

    // Implementation of GLRotationIface
    virtual void updateGlRotation( int xRot, int yRot, int zRot ) override;

    void release();

  private:
    ModelViewerGLWidget* widget_;
    std::mutex widgetMutex_;
};

} // namespace phywidgets

#endif // GLROTATIONMODELADAPTER_H
