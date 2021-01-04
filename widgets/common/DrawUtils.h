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

    static void drawSphere( const Vector& coordinate, double radius );
    static void drawLine( const Vector& start, const Vector& end, float lineWidth );
    static void drawDirectionVector(
        const Vector& start, const Vector& end, float lineWidth, float radius );
};

} // namespace phywidgets

#endif // DRAWUTILS_H