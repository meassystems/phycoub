#ifndef DRAWUTILS_H
#define DRAWUTILS_H

#include "Vector.h"

namespace phywidgets
{

using namespace phycoub;

class DrawUtils final
{
  public:
    DrawUtils() = delete;

    static void drawSphere( const Vector& coordinate, float radius );
    static void drawLine( const Vector& start, const Vector& end, float lineWidth );
    static void drawCube( const Vector& coordinate, float size, float lineWidth );
    static void drawDirectionVector(
        const Vector& start, const Vector& end, float lineWidth, float radius );
};

} // namespace phywidgets

#endif // DRAWUTILS_H