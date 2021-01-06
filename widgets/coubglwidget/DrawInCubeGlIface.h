#ifndef DRAWINCUBEGLIFACE_H
#define DRAWINCUBEGLIFACE_H

#include <memory>

namespace phywidgets
{

class DrawInCubeGlIface
{
  public:
    virtual ~DrawInCubeGlIface() = default;

    virtual void draw() = 0;
};

using DrawInCubeGlPtr = std::shared_ptr< DrawInCubeGlIface >;
using DrawInCubeGlWeak = std::weak_ptr< DrawInCubeGlIface >;

} // namespace phywidgets

#endif // DRAWINCUBEGLIFACE_H