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
    void drowModelingCoub();
    void drowParticlesWithColorsByGroup( const ParticleGroupList& particleGroupList );
    void drowVector( const Vector& vector );
    void drowTrajectory();

    void drowSphere( const Vector& coordinate, double radius );
    void drowCube( const Vector& coordinate, double size );

    static Vector mashtabVector( const Vector& coordinate, const Vector& mashtab );

    bool drowTrajectoryFlag_ = false;
    bool updateTrajectoryFlag_ = false;
    std::unordered_map< IDType, std::list< Vector > > trajectory_;

    GetCoubSizeAdapterWeakPtr getCoubSizeAdapterWeak_;
    GetParticlesAdapterWeakPtr getParticlesAdapterWeak_;

    QGLWidget* gLWidget_ = nullptr;
    Vector coubSize_;

    static const Vector origin_;
    constexpr static std::array< Qt::GlobalColor, 5 > colorsForGroup_
        = { Qt::green, Qt::red, Qt::blue, Qt::yellow, Qt::magenta };
};

using PhyCoubGLPtr = std::shared_ptr< PhyCoubGL >;

} // namespace phywidgets

#endif // PHYCOUBGL_H
