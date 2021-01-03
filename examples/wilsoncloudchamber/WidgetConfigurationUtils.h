#ifndef WIDGETCONFIGURATIONUTILS_H
#define WIDGETCONFIGURATIONUTILS_H

#include <QWidget>

#include "GLRotationController.h"
#include "ValueControllerAdapterIface.h"

namespace phywilsoncloudchamber
{

using namespace phywidgets;

class WidgetConfigurationUtils final
{
  public:
    WidgetConfigurationUtils() = delete;

    static void initializeParticleSourceWidget( QWidget* widget,
        GLRotationControllerWeakPtr gLRotationControllerWeak,
        VectorControllerAdapterWeakPtr directionControllerAdapter,
        DoubleControllerAdapterWeakPtr angleControllerAdapter,
        DoubleControllerAdapterWeakPtr bornPeriodControllerAdapter,
        DoubleControllerAdapterWeakPtr bornEnergyControllerAdapter, QString sourceName );
};

} // namespace phywilsoncloudchamber

#endif // WIDGETCONFIGURATIONUTILS_H
