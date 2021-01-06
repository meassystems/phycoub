#ifndef HOMOGENEOUSFIELDINCUBEGL_H
#define HOMOGENEOUSFIELDINCUBEGL_H

#include <QGLWidget>
#include <list>

#include "DrawInCubeGlIface.h"
#include "ValueControllerAdapterIface.h"

namespace phywidgets
{

using namespace phycoub;

class HomogeneousFieldInCubeGL
    : public QGLWidget
    , public DrawInCubeGlIface
{
  public:
    HomogeneousFieldInCubeGL( QWidget* parent = nullptr );
    virtual ~HomogeneousFieldInCubeGL() override = default;

    void setDirectionController( VectorControllerAdapterWeakPtr directionController );

    void setShowFlag( bool isShow );
    bool isShow() const;

    void setColor( QColor color );

    // Implementation of DrawInCubeGlIface
    virtual void draw() override;

  private:
    struct FieldVector
    {
        FieldVector( Vector theBegin, Vector theEnd );

        Vector begin;
        Vector end;
    };

    void updateFieldVectors();

    bool _isShow = false;
    VectorControllerAdapterWeakPtr _directionControllerWeak;
    Vector _priviesDirection{ 1. };

    Vector _uBasis{ 0. };
    Vector _vBasis{ 0. };
    std::list< FieldVector > _fieldVectors;

    QColor _color = Qt::cyan;

    constexpr static unsigned numCountPointPerDirection = 5;
};

} // namespace phywidgets

#endif // HOMOGENEOUSFIELDINCUBEGL_H