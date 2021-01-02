#ifndef PARICLEREMOVECONTROLLERADAPTERIFACE_H
#define PARICLEREMOVECONTROLLERADAPTERIFACE_H

#include <memory>

#include "HasId.h"

namespace phywidgets
{

class ParticleRemoveControllerAdapterIface
{
  public:
    virtual ~ParticleRemoveControllerAdapterIface() = default;

    virtual void removeParticle( phycoub::IDType id ) = 0;
};

using ParticleRemoveControllerAdapterWeakPtr
    = std::weak_ptr< ParticleRemoveControllerAdapterIface >;

} // namespace phywidgets

#endif // PARICLEREMOVECONTROLLERADAPTERIFACE_H
