#ifndef GETCOUBSIZEADAPTERIFACE_H
#define GETCOUBSIZEADAPTERIFACE_H

#include <memory>

#include "Vector.h"

namespace phywidgets
{

class GetCoubSizeAdapterIface
{
  public:
    virtual ~GetCoubSizeAdapterIface() = default;

    virtual phycoub::Vector getCoubSize() const = 0;
};

using GetCoubSizeAdapterWeakPtr = std::weak_ptr< GetCoubSizeAdapterIface >;

} // namespace phywidgets

#endif // GETCOUBSIZEADAPTERIFACE_H
