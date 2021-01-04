#ifndef TRAJECTORY_H
#define TRAJECTORY_H

#include <list>
#include "Vector.h"

namespace phywidgets
{

using namespace phycoub;

class Trajectory final
{
  public:
    Trajectory( unsigned maxPointCount, double pointAngle, double minLinearSize );
    ~Trajectory() = default;

    void update( const Vector& coordinate );
    void clear();

    void drawTrajectory() const;

  private:
    unsigned _maxPointCount = 0;
    double _pointCosAngle = 0.;
    double _minLinearSize = 0.;

    std::list< Vector > _trajectory;
};

} // namespace phywidgets

#endif // TRAJECTORY_H