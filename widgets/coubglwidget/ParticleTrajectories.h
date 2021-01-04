#ifndef PARTICLETRAJECTORIES_H
#define PARTICLETRAJECTORIES_H

#include <list>
#include <unordered_map>

#include "HasId.h"
#include "Vector.h"
#include "ParticleGroupList.h"

namespace phywidgets
{

using namespace phycoub;

class ParticleTrajectories final {
  public:
    ParticleTrajectories() = default;
    ~ParticleTrajectories() = default;

    void drawTrajectory() const;

    void update(const ParticleGroupList& particleGroupList);
    void clean();

  private:
    std::unordered_map< IDType, std::list< Vector > > _trajectories;
};

} // phywidgets

#endif // PARTICLETRAJECTORIES_H