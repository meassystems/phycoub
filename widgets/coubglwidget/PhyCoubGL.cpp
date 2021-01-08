#include "PhyCoubGL.h"

#include <QOpenGLFunctions>
#include <QGL>

#if defined( WIN32 )
#    include <GL/glu.h>
#elif defined( DARWIN )
#    include <OpenGL/glu.h>
#endif

#include <unordered_set>

#include "DrawUtils.h"
#include "ParticleGroupList.h"

namespace phywidgets
{

PhyCoubGL::PhyCoubGL( QGLWidget* gLWidget )
    : gLWidget_( gLWidget )
{
}

// virtual override
void PhyCoubGL::onStart()
{
    updateTrajectoryFlag_ = true;
}

// virtual override
void PhyCoubGL::onStop()
{
    updateTrajectoryFlag_ = false;
}

void PhyCoubGL::setGetCoubSizeAdapter( GetCoubSizeAdapterWeakPtr getCoubSizeAdapterWeak )
{
    getCoubSizeAdapterWeak_ = getCoubSizeAdapterWeak;
    if ( auto getCoubSizeAdapter = getCoubSizeAdapterWeak_.lock() )
    {
        coubSize_ = getCoubSizeAdapter->getCoubSize();
    }
}

void PhyCoubGL::setGetParticleForGLAdapter(
    GetParticlesAdapterWeakPtr getParticlesAdapterWeak )
{
    getParticlesAdapterWeak_ = getParticlesAdapterWeak;
}

void PhyCoubGL::updateScene()
{
    if ( auto getParticlesForGLAdapter = getParticlesAdapterWeak_.lock() )
    {
        drawModelingCube();
        drawParticlesWithColorsByGroup( getParticlesForGLAdapter->getParticles() );
        drawTrajectory();
    }
}

void PhyCoubGL::setDrowTrajectoryFlag( bool flag )
{
    drawTrajectoryFlag_ = flag;
    if ( !drawTrajectoryFlag_ )
    {
        trajectory_.clear();
    }
}

bool PhyCoubGL::getDrowTrajectoryFlag() const
{
    return drawTrajectoryFlag_;
}

void PhyCoubGL::drawModelingCube()
{
    gLWidget_->qglColor( Qt::white );
    DrawUtils::drawCube( Vector{ 0, 0, 0 }, numSizeCube, 2.f );
}

void PhyCoubGL::drawParticlesWithColorsByGroup(
    const ParticleGroupList& particleGroupList )
{
    using namespace phycoub;

    std::unordered_set< IDType > trajectoryParticleIdList;
    if ( drawTrajectoryFlag_ )
    {
        for ( const auto& [ key, value ] : trajectory_ )
        {
            trajectoryParticleIdList.emplace( key );
        }
    }

    size_t colorIndex = 0;
    particleGroupList.forEachGroup( [ this, &trajectoryParticleIdList, &colorIndex ](
                                        ParticleGroupPtr group ) {
        gLWidget_->qglColor( colorsForGroup_[ colorIndex ] );

        for ( ParticlePtr particle : *group )
        {
            const Vector& particleCoordinate = particle->getCoordinate();
            const Vector scaleCoordinate = scaleVector( particleCoordinate, coubSize_ );

            DrawUtils::drawSphere( scaleCoordinate, 0.01 );

            if ( drawTrajectoryFlag_ )
            {
                trajectoryParticleIdList.extract( particle->getId() );

                if ( updateTrajectoryFlag_ )
                {
                    auto particleTrajectoryItr = trajectory_.find( particle->getId() );
                    if ( particleTrajectoryItr != trajectory_.end() )
                    {
                        particleTrajectoryItr->second.update( scaleCoordinate );
                    }
                    else
                    {
                        Trajectory particleTrajectory{ numMaxTrajectoryPontCount,
                            trajectoryPointAngle, numSizeCube };
                        trajectory_.emplace( particle->getId(), particleTrajectory );
                    }
                }
            }
        }
        ++colorIndex;
    } );

    if ( drawTrajectoryFlag_ )
    {
        for ( auto id : trajectoryParticleIdList )
        {
            trajectory_.extract( id );
        }
    }
}

void PhyCoubGL::drawTrajectory()
{
    gLWidget_->qglColor( Qt::yellow );
    for ( const auto& particleTrajectory : trajectory_ )
    {
        particleTrajectory.second.drawTrajectory();
    }
}

// static
Vector PhyCoubGL::scaleVector( const Vector& coordinate, const Vector& ratio )
{
    const Vector scaledVector = Vector{
        coordinate.x() / ratio.x(),
        coordinate.y() / ratio.y(),
        coordinate.z() / ratio.z(),
    };
    return scaledVector;
}

} // namespace phywidgets
