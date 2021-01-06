#include "HomogeneousFieldInCubeGL.h"

#include <QGL>
#include <QOpenGLFunctions>

#if defined( WIN32 )
#    include <GL/glu.h>
#elif defined( DARWIN )
#    include <OpenGL/glu.h>
#endif

#include "VectorUtils.h"
#include "DrawUtils.h"

namespace phywidgets
{

using namespace phycoub;

HomogeneousFieldInCubeGL::FieldVector::FieldVector( Vector theBegin, Vector theEnd )
    : begin( theBegin )
    , end( theEnd )
{
}

HomogeneousFieldInCubeGL::HomogeneousFieldInCubeGL( QWidget* parent /* = nullptr */ )
    : QGLWidget( parent )
{
    updateFieldVectors();
}

void HomogeneousFieldInCubeGL::setDirectionController(
    VectorControllerAdapterWeakPtr directionController )
{
    _directionControllerWeak = directionController;
}

void HomogeneousFieldInCubeGL::setColor( QColor color )
{
    _color = color;
}

void HomogeneousFieldInCubeGL::setShowFlag( bool isShow )
{
    _isShow = isShow;
}

bool HomogeneousFieldInCubeGL::isShow() const
{
    return _isShow;
}

// virtual override
void HomogeneousFieldInCubeGL::draw()
{
    if ( !_isShow )
    {
        return;
    }

    Vector newDirection = _priviesDirection;
    if ( auto directionController = _directionControllerWeak.lock() )
    {
        newDirection = directionController->getValue();
    }

    if ( newDirection != _priviesDirection )
    {
        _priviesDirection = newDirection;
        updateFieldVectors();
    }

    qglColor( _color );
    for ( const auto& fieldVector : _fieldVectors )
    {
        DrawUtils::drawDirectionVector( fieldVector.begin, fieldVector.end, 1.f, .01f );
    }
}

void HomogeneousFieldInCubeGL::updateFieldVectors()
{
    // Todo mby changed?
    Vector cubeWhd{ 1. };

    _vBasis = VectorUtils::calculatePerpendicular( _priviesDirection );
    _uBasis = VectorUtils::calculatePerpendicular( _priviesDirection, _vBasis );

    _fieldVectors.clear();

    const Vector center = cubeWhd / 2;
    const double maxLinearSize = cubeWhd.getMax();
    const double scaleCoef = 1.5 * maxLinearSize;
    const double step = scaleCoef / numCountPointPerDirection;

    Vector vIterator = center - _priviesDirection * scaleCoef / 2
        - _vBasis * scaleCoef / 2 - _uBasis * scaleCoef / 2;
    for ( unsigned i = 0; i <= numCountPointPerDirection; ++i )
    {
        Vector uIterator = vIterator;
        for ( unsigned j = 0; j <= numCountPointPerDirection; ++j )
        {
            _fieldVectors.push_back(
                FieldVector{ uIterator, uIterator + _priviesDirection * scaleCoef } );

            uIterator = uIterator + _uBasis * step;
        }
        vIterator = vIterator + _vBasis * step;
    }
}

} // namespace phywidgets