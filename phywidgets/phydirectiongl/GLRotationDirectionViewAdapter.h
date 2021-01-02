#ifndef GLROTTIONCONTROLLERVIEWADAPTER_H
#define GLROTTIONCONTROLLERVIEWADAPTER_H

#include <mutex>

#include "GLRotationIface.h"

namespace phywidgets {

class PhyDirectionGLWidget;

class GLRotationDirectionViewAdapter final : public GLRotationIface {
public:
  GLRotationDirectionViewAdapter(PhyDirectionGLWidget *widget);
  virtual ~GLRotationDirectionViewAdapter() override;

  // Implementation of GLRotationIface
  virtual void updateGlRotation(int xRot, int yRot, int zRot) override;

  void release();

private:
  PhyDirectionGLWidget *widget_;
  std::mutex widgetMutex_;
};

} // namespace phywidgets

#endif // GLROTTIONCONTROLLERVIEWADAPTER_H
