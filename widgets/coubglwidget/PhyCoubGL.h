#ifndef PHYCOUBGL_H
#define PHYCOUBGL_H

#include <unordered_map>
#include <list>
#include <array>
#include <memory>
#include <QColor>
#include <QGLWidget>
#include <QTableWidget>

#include "GetCoubSizeAdapterIface.h"
#include "GetParticlesAdapterIface.h"
#include "PhyCoubControllerSubscriberIface.h"
#include "Trajectory.h"
#include "Vector.h"
#include "ParticleGroupList.h"
#include "HasId.h"

namespace phywidgets
{

using namespace phycoub;

class PhyCoubGL final : public PhyCoubControllerSubscriberIface
{
  public:
    PhyCoubGL( QGLWidget* gLWidget );
    virtual ~PhyCoubGL() override = default;

    // Implementation of PhyCoubControllerSubscriberIface
    virtual void onStart() override;
    virtual void onStop() override;

    void setGetCoubSizeAdapter( GetCoubSizeAdapterWeakPtr getCoubSizeAdapterWeak );
    void setGetParticleForGLAdapter( GetParticlesAdapterWeakPtr getParticlesAdapterWeak );
    void updateScene();

    void setDrowTrajectoryFlag( bool flag );
    bool getDrowTrajectoryFlag() const;

  private:
    void drawModelingCube();
    void drawParticlesWithColorsByGroup( const ParticleGroupList& particleGroupList );
    void drawTrajectory();

    static Vector scaleVector( const Vector& coordinate, const Vector& ratio );

    bool drawTrajectoryFlag_ = false;
    bool updateTrajectoryFlag_ = false;
    std::unordered_map< IDType, Trajectory > trajectory_;

    GetCoubSizeAdapterWeakPtr getCoubSizeAdapterWeak_;
    GetParticlesAdapterWeakPtr getParticlesAdapterWeak_;

    QGLWidget* gLWidget_ = nullptr;
    Vector coubSize_;

    constexpr static unsigned numMaxTrajectoryPontCount = 20;
    constexpr static double trajectoryPointAngle = 0.2;

    constexpr static unsigned numSizeCube = 1;
    constexpr static unsigned numTrajectoryPointsPerParticle = 100;
    constexpr static std::array< Qt::GlobalColor, 5 > colorsForGroup_
        = { Qt::green, Qt::red, Qt::blue, Qt::yellow, Qt::magenta };
};

using PhyCoubGLPtr = std::shared_ptr< PhyCoubGL >;

} // namespace phywidgets

#endif // PHYCOUBGL_H
