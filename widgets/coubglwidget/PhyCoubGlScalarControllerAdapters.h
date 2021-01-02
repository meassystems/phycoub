#ifndef PHYCOUBGLSCALARCONTROLLERADAPTERS_H
#define PHYCOUBGLSCALARCONTROLLERADAPTERS_H

#include <memory>

#include "ValueControllerAdapterIface.h"
#include "PhyCoubGL.h"

namespace phywidgets
{

using TrajectoryScalarControllerAdapter = ValueControllerAdapter< bool, PhyCoubGL,
    &PhyCoubGL::getDrowTrajectoryFlag, &PhyCoubGL::setDrowTrajectoryFlag >;
using TrajectoryScalarControllerAdapterPtr
    = std::shared_ptr< TrajectoryScalarControllerAdapter >;

} // namespace phywidgets

#endif // PHYCOUBGLSCALARCONTROLLERADAPTERS_H
