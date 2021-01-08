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
    glTranslatef( static_cast< float >( coordinate.x() ),
        static_cast< float >( coordinate.y() ), static_cast< float >( coordinate.z() ) );
    gluSphere( quadric, radius, 36, 36 );
    gluDeleteQuadric( quadric );
    glPopMatrix();
}

// static
void DrawUtils::drawLine( const Vector& start, const Vector& end, float lineWidth )
{
    glLineWidth( lineWidth );
    glBegin( GL_LINES );

    glVertex3f( static_cast< float >( start.x() ), static_cast< float >( start.y() ),
        static_cast< float >( start.z() ) );

    glVertex3f( static_cast< float >( end.x() ), static_cast< float >( end.y() ),
        static_cast< float >( end.z() ) );

    glEnd();
}

// static
void DrawUtils::drawCube( const Vector& coordinate, float size, float lineWidth )
{
    drawLine( Vector{ coordinate.x(), coordinate.y(), coordinate.z() + size },
        Vector{ coordinate.x(), coordinate.y() + size, coordinate.z() + size }, lineWidth );

    drawLine( Vector{ coordinate.x(), coordinate.y() + size, coordinate.z() + size },
        coordinate + size, lineWidth );

    drawLine( coordinate + size,
        Vector{ coordinate.x() + size, coordinate.y(), coordinate.z() + size }, lineWidth );

    drawLine( Vector{ coordinate.x() + size, coordinate.y(), coordinate.z() + size },
        Vector{ coordinate.x(), coordinate.y(), coordinate.z() + size }, lineWidth );

    drawLine( coordinate, Vector{ coordinate.x(), coordinate.y() + size, coordinate.z() },
        lineWidth );

    drawLine( Vector{ coordinate.x(), coordinate.y() + size, coordinate.z() },
        Vector{ coordinate.x() + size, coordinate.y() + size, coordinate.z() }, lineWidth );

    drawLine( Vector{ coordinate.x() + size, coordinate.y() + size, coordinate.z() },
        Vector{ coordinate.x() + size, coordinate.y(), coordinate.z() }, lineWidth );

    drawLine( Vector{ coordinate.x() + size, coordinate.y(), coordinate.z() }, coordinate,
        lineWidth );

    drawLine( Vector{ coordinate.x(), coordinate.y(), coordinate.z() + size }, coordinate,
        lineWidth );

    drawLine( Vector{ coordinate.x(), coordinate.y() + size, coordinate.z() + size },
        Vector{ coordinate.x(), coordinate.y() + size, coordinate.z() }, lineWidth );

    drawLine( coordinate + size,
        Vector{ coordinate.x() + size, coordinate.y() + size, coordinate.z() }, lineWidth );

    drawLine( Vector{ coordinate.x() + size, coordinate.y(), coordinate.z() + size },
        Vector{ coordinate.x() + size, coordinate.y(), coordinate.z() }, lineWidth );
}

// static
void DrawUtils::drawDirectionVector(
    const Vector& start, const Vector& end, float lineWidth, float radius )
{
    drawLine( start, end, lineWidth );
    drawSphere( end, radius );
}

} // namespace phywidgets