#include "DrawUtils.h"

#if defined( WIN32 )
#    include <windows.h>
#    include <GL/glu.h>
#elif defined( DARWIN )
#    include <OpenGL/glu.h>
#endif

namespace phywidgets
{

// static
void DrawUtils::drawSphere( const Vector& coordinate, float radius )
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

// static
void DrawUtils::drawLine( const Vector& start, const Vector& end, float lineWidth )
{
    glLineWidth( lineWidth );
    glBegin( GL_LINES );

    glVertex3f( static_cast< float >( start.x_ ), static_cast< float >( start.y_ ),
        static_cast< float >( start.z_ ) );

    glVertex3f( static_cast< float >( end.x_ ), static_cast< float >( end.y_ ),
        static_cast< float >( end.z_ ) );

    glEnd();
}

// static
void DrawUtils::drawCube( const Vector& coordinate, float size, float lineWidth )
{
    drawLine( Vector{ coordinate.x_, coordinate.y_, coordinate.z_ + size },
        Vector{ coordinate.x_, coordinate.y_ + size, coordinate.z_ + size }, lineWidth );

    drawLine( Vector{ coordinate.x_, coordinate.y_ + size, coordinate.z_ + size },
        coordinate + size, lineWidth );

    drawLine( coordinate + size,
        Vector{ coordinate.x_ + size, coordinate.y_, coordinate.z_ + size }, lineWidth );

    drawLine( Vector{ coordinate.x_ + size, coordinate.y_, coordinate.z_ + size },
        Vector{ coordinate.x_, coordinate.y_, coordinate.z_ + size }, lineWidth );

    drawLine( coordinate, Vector{ coordinate.x_, coordinate.y_ + size, coordinate.z_ },
        lineWidth );

    drawLine( Vector{ coordinate.x_, coordinate.y_ + size, coordinate.z_ },
        Vector{ coordinate.x_ + size, coordinate.y_ + size, coordinate.z_ }, lineWidth );

    drawLine( Vector{ coordinate.x_ + size, coordinate.y_ + size, coordinate.z_ },
        Vector{ coordinate.x_ + size, coordinate.y_, coordinate.z_ }, lineWidth );

    drawLine( Vector{ coordinate.x_ + size, coordinate.y_, coordinate.z_ }, coordinate,
        lineWidth );

    drawLine( Vector{ coordinate.x_, coordinate.y_, coordinate.z_ + size }, coordinate,
        lineWidth );

    drawLine( Vector{ coordinate.x_, coordinate.y_ + size, coordinate.z_ + size },
        Vector{ coordinate.x_, coordinate.y_ + size, coordinate.z_ }, lineWidth );

    drawLine( coordinate + size,
        Vector{ coordinate.x_ + size, coordinate.y_ + size, coordinate.z_ }, lineWidth );

    drawLine( Vector{ coordinate.x_ + size, coordinate.y_, coordinate.z_ + size },
        Vector{ coordinate.x_ + size, coordinate.y_, coordinate.z_ }, lineWidth );
}

// static
void DrawUtils::drawDirectionVector(
    const Vector& start, const Vector& end, float lineWidth, float radius )
{
    drawLine( start, end, lineWidth );
    drawSphere( end, radius );
}

} // namespace phywidgets