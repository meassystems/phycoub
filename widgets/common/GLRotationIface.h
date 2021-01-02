#ifndef GLROTATIONIFACE_H
#define GLROTATIONIFACE_H

#include <memory>

namespace phywidgets
{

class GLRotationIface
{
  public:
    GLRotationIface() = default;
    virtual ~GLRotationIface() = default;

    virtual void updateGlRotation( int xRot, int yRot, int zRot ) = 0;
};

using GLRotationPtr = std::shared_ptr< GLRotationIface >;

} // namespace phywidgets

#endif // GLROTATIONIFACE_H
