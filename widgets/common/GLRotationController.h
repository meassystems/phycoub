#ifndef GLROTATIONCONTROLLER_H
#define GLROTATIONCONTROLLER_H

#include <list>
#include <memory>

#include "GLRotationIface.h"

namespace phywidgets
{

class GLRotationController
{
  public:
    GLRotationController() = default;

    void updateRotationX( int angle );
    void updateRotationY( int angle );
    void updateRotationZ( int angle );

    void subscribeForUpdates( GLRotationPtr glSubscriber );

  private:
    void notifySubscribers();

    static void normalizeAngle( int* angle );

    int xRot_ = 0;
    int yRot_ = 0;
    int zRot_ = 0;

    std::list< std::weak_ptr< GLRotationIface > > glSubscribers_;
};

using GLRotationControllerWeakPtr = std::weak_ptr< GLRotationController >;
using GLRotationControllerPtr = std::shared_ptr< GLRotationController >;

} // namespace phywidgets

#endif // GLROTATIONCONTROLLER_H
