#include "PhyCoubGL.h"

#include <QOpenGLFunctions>
#include <QGL>

#if defined( WIN32 )
#    include <GL/glu.h>
#elif defined( DARWIN )
#    include <OpenGL/glu.h>
#endif

#include <unordered_set>

#include "ParticleGroupList.h"

namespace phywidgets
{

// static
const Vector PhyCoubGL::origin_ = Vector{ 0.5, 0.5, 0.5 };

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
        drowModelingCoub();
        drowParticlesWithColorsByGroup( getParticlesForGLAdapter->getParticles() );
        drowTrajectory();
    }
}

void PhyCoubGL::setDrowTrajectoryFlag( bool flag )
{
    drowTrajectoryFlag_ = flag;
    if ( !drowTrajectoryFlag_ )
    {
        trajectory_.clear();
    }
}

bool PhyCoubGL::getDrowTrajectoryFlag() const
{
    return drowTrajectoryFlag_;
}

void PhyCoubGL::drowModelingCoub()
{
    gLWidget_->qglColor( Qt::white );
    drowCube( Vector{ 0, 0, 0 }, 1 );
}

void PhyCoubGL::drowParticlesWithColorsByGroup(
    const ParticleGroupList& particleGroupList )
{
    using namespace phycoub;

    std::unordered_set< IDType > trajectoryParticleIdList;
    if ( drowTrajectoryFlag_ )
    {
        for ( const auto& [ key, value ] : trajectory_ )
        {
            trajectoryParticleIdList.emplace( key );
        }
    }

    size_t colorIndex = 0;
    particleGroupList.forEachGroup(
        [this, &trajectoryParticleIdList, &colorIndex]( ParticleGroupPtr group ) {
            gLWidget_->qglColor( colorsForGroup_[ colorIndex ] );

            for ( ParticlePtr particle : *group )
            {
                const Vector& particleCoordinate = particle->getCoordinate();
                const Vector mashtabedOriginCoordinate
                    = mashtabVector( particleCoordinate, coubSize_ ) - origin_;
                drowSphere( mashtabedOriginCoordinate, 0.01 );

                if ( drowTrajectoryFlag_ )
                {
                    trajectoryParticleIdList.extract( particle->getId() );

                    if ( updateTrajectoryFlag_ )
                    {
                        auto& trajectoryVector = trajectory_[ particle->getId() ];
                        trajectoryVector.push_back( mashtabedOriginCoordinate );
                        if ( trajectoryVector.size() > 100 )
                        {
                            trajectoryVector.pop_front();
                        }
                    }
                }
            }
            ++colorIndex;
        } );

    if ( drowTrajectoryFlag_ )
    {
        for ( auto id : trajectoryParticleIdList )
        {
            trajectory_.extract( id );
        }
    }
}

void PhyCoubGL::drowTrajectory()
{
    gLWidget_->qglColor( Qt::cyan );
    for ( const auto& particleTrajectory : trajectory_ )
    {
        for ( const auto& coordinateOfTrajectory : particleTrajectory.second )
        {
            drowSphere( coordinateOfTrajectory, 0.001 );
        }
    }
}

void PhyCoubGL::drowSphere( const Vector& coordinate, double radius )
{
    glPushMatrix();
    glScalef( 1, 1, 1 );
    GLUquadricObj* quadric = gluNewQuadric();
    gluQuadricNormals( quadric, GLU_SMOOTH );
    gluQuadricDrawStyle( quadric, GLU_LINE );
    glTranslatef( static_cast< float >( coordinate.x_ ),
        static_cast< float >( coordinate.y_ ), static_cast< float >( coordinate.z_ ) );
    gluSphere( quadric, radius, 36, 36 );
    gluDeleteQuadric( quadric );
    glPopMatrix();
}

void PhyCoubGL::drowCube( const Vector& coordinate, double size )
{
    glLineWidth( 2.0f );
    glBegin( GL_LINES );
    glVertex3f( static_cast< float >( coordinate.x_ - 0.5 * size ),
        static_cast< float >( coordinate.y_ - 0.5 * size ),
        static_cast< float >( coordinate.z_ + 0.5 * size ) );
    glVertex3f( static_cast< float >( coordinate.x_ - 0.5 * size ),
        static_cast< float >( coordinate.y_ + 0.5 * size ),
        static_cast< float >( coordinate.z_ + 0.5 * size ) );

    glVertex3f( static_cast< float >( coordinate.x_ - 0.5 * size ),
        static_cast< float >( coordinate.y_ + 0.5 * size ),
        static_cast< float >( coordinate.z_ + 0.5 * size ) );
    glVertex3f( static_cast< float >( coordinate.x_ + 0.5 * size ),
        static_cast< float >( coordinate.y_ + 0.5 * size ),
        static_cast< float >( coordinate.z_ + 0.5 * size ) );

    glVertex3f( static_cast< float >( coordinate.x_ + 0.5 * size ),
        static_cast< float >( coordinate.y_ + 0.5 * size ),
        static_cast< float >( coordinate.z_ + 0.5 * size ) );
    glVertex3f( static_cast< float >( coordinate.x_ + 0.5 * size ),
        static_cast< float >( coordinate.y_ - 0.5 * size ),
        static_cast< float >( coordinate.z_ + 0.5 * size ) );

    glVertex3f( static_cast< float >( coordinate.x_ + 0.5 * size ),
        static_cast< float >( coordinate.y_ - 0.5 * size ),
        static_cast< float >( coordinate.z_ + 0.5 * size ) );
    glVertex3f( static_cast< float >( coordinate.x_ - 0.5 * size ),
        static_cast< float >( coordinate.y_ - 0.5 * size ),
        static_cast< float >( coordinate.z_ + 0.5 * size ) );
    //
    glVertex3f( static_cast< float >( coordinate.x_ - 0.5 * size ),
        static_cast< float >( coordinate.y_ - 0.5 * size ),
        static_cast< float >( coordinate.z_ - 0.5 * size ) );
    glVertex3f( static_cast< float >( coordinate.x_ - 0.5 * size ),
        static_cast< float >( coordinate.y_ + 0.5 * size ),
        static_cast< float >( coordinate.z_ - 0.5 * size ) );

    glVertex3f( static_cast< float >( coordinate.x_ - 0.5 * size ),
        static_cast< float >( coordinate.y_ + 0.5 * size ),
        static_cast< float >( coordinate.z_ - 0.5 * size ) );
    glVertex3f( static_cast< float >( coordinate.x_ + 0.5 * size ),
        static_cast< float >( coordinate.y_ + 0.5 * size ),
        static_cast< float >( coordinate.z_ - 0.5 * size ) );

    glVertex3f( static_cast< float >( coordinate.x_ + 0.5 * size ),
        static_cast< float >( coordinate.y_ + 0.5 * size ),
        static_cast< float >( coordinate.z_ - 0.5 * size ) );
    glVertex3f( static_cast< float >( coordinate.x_ + 0.5 * size ),
        static_cast< float >( coordinate.y_ - 0.5 * size ),
        static_cast< float >( coordinate.z_ - 0.5 * size ) );

    glVertex3f( static_cast< float >( coordinate.x_ + 0.5 * size ),
        static_cast< float >( coordinate.y_ - 0.5 * size ),
        static_cast< float >( coordinate.z_ - 0.5 * size ) );
    glVertex3f( static_cast< float >( coordinate.x_ - 0.5 * size ),
        static_cast< float >( coordinate.y_ - 0.5 * size ),
        static_cast< float >( coordinate.z_ - 0.5 * size ) );
    //
    glVertex3f( static_cast< float >( coordinate.x_ - 0.5 * size ),
        static_cast< float >( coordinate.y_ - 0.5 * size ),
        static_cast< float >( coordinate.z_ + 0.5 * size ) );
    glVertex3f( static_cast< float >( coordinate.x_ - 0.5 * size ),
        static_cast< float >( coordinate.y_ - 0.5 * size ),
        static_cast< float >( coordinate.z_ - 0.5 * size ) );

    glVertex3f( static_cast< float >( coordinate.x_ - 0.5 * size ),
        static_cast< float >( coordinate.y_ + 0.5 * size ),
        static_cast< float >( coordinate.z_ + 0.5 * size ) );
    glVertex3f( static_cast< float >( coordinate.x_ - 0.5 * size ),
        static_cast< float >( coordinate.y_ + 0.5 * size ),
        static_cast< float >( coordinate.z_ - 0.5 * size ) );

    glVertex3f( static_cast< float >( coordinate.x_ + 0.5 * size ),
        static_cast< float >( coordinate.y_ + 0.5 * size ),
        static_cast< float >( coordinate.z_ + 0.5 * size ) );
    glVertex3f( static_cast< float >( coordinate.x_ + 0.5 * size ),
        static_cast< float >( coordinate.y_ + 0.5 * size ),
        static_cast< float >( coordinate.z_ - 0.5 * size ) );

    glVertex3f( static_cast< float >( coordinate.x_ + 0.5 * size ),
        static_cast< float >( coordinate.y_ - 0.5 * size ),
        static_cast< float >( coordinate.z_ + 0.5 * size ) );
    glVertex3f( static_cast< float >( coordinate.x_ + 0.5 * size ),
        static_cast< float >( coordinate.y_ - 0.5 * size ),
        static_cast< float >( coordinate.z_ - 0.5 * size ) );
    glEnd();
}

// static
Vector PhyCoubGL::mashtabVector( const Vector& coordinate, const Vector& mashtab )
{
    const Vector mashtabedVector = Vector{
        coordinate.x_ / mashtab.x_,
        coordinate.y_ / mashtab.y_,
        coordinate.z_ / mashtab.z_,
    };
    return mashtabedVector;
}

} // namespace phywidgets
