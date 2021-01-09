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
#include "LinearAlgebraEquationUtils.h"

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
    std::list< Vector > fieldVectorBegins;

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
            fieldVectorBegins.push_back( uIterator );
            uIterator = uIterator + _uBasis * step;
        }
        vIterator = vIterator + _vBasis * step;
    }

    std::list< PlaneEquation > cubePlanes
        = { { cubeWhd.x(), .0, .0, .0 }, { cubeWhd.x(), .0, .0, -cubeWhd.x() },
              { 0, cubeWhd.y(), .0, .0 }, { .0, cubeWhd.y(), .0, -cubeWhd.y() },
              { .0, .0, cubeWhd.z(), .0 }, { .0, .0, cubeWhd.z(), -cubeWhd.z() } };

    for ( const auto& fieldVector : fieldVectorBegins )
    {
        StraightLineEquation fieldVectorEquation{
            { _vBasis.x(), _vBasis.y(), _vBasis.z(),
                -( _vBasis._vector.cwiseProduct( fieldVector._vector ).sum() ) },
            { _uBasis.x(), _uBasis.y(), _uBasis.z(),
                -( _uBasis._vector.cwiseProduct( fieldVector._vector ).sum() ) }
        };

        std::list< Vector > onCubeIntersectionPoints;
        for ( const auto& cubePlaneEq : cubePlanes )
        {
            auto result
                = LinearAlgebraEquationUtils::findStraightLineAndPlaneIntersectionPoint(
                    fieldVectorEquation, cubePlaneEq );

            if ( result.decisionExist && result.result._vector.minCoeff() >= 0
                && ( result.result._vector.array() <= cubeWhd._vector.array() ).all() )
            {
                onCubeIntersectionPoints.push_back( result.result );
            }
        }

        if ( onCubeIntersectionPoints.size() < 2 )
        {
            continue;
        }

        const Vector resultFieldVectorDirection = *( ++onCubeIntersectionPoints.begin() )
            - *( onCubeIntersectionPoints.begin() );
        if ( resultFieldVectorDirection._vector.dot( _priviesDirection._vector ) > 0 )
        {
            _fieldVectors.push_back( FieldVector{ *onCubeIntersectionPoints.begin(),
                *( ++onCubeIntersectionPoints.begin() ) } );
        }
        else
        {
            _fieldVectors.push_back( FieldVector{ *( ++onCubeIntersectionPoints.begin() ),
                *onCubeIntersectionPoints.begin() } );
        }
    }
}

} // namespace phywidgets