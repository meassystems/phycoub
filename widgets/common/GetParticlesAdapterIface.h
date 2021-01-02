#ifndef GETPARTICLESFORGLIFACE_H
#define GETPARTICLESFORGLIFACE_H

#include <memory>

#include "ParticleGroupList.h"

namespace phywidgets
{

class GetParticlesAdapterIface
{
  public:
    virtual ~GetParticlesAdapterIface() = default;

    virtual phycoub::ParticleGroupList getParticles() const = 0;
};

using GetParticlesAdapterWeakPtr = std::weak_ptr< GetParticlesAdapterIface >;

} // namespace phywidgets

#endif // GETPARTICLESFORGLIFACE_H
