#ifndef PHYDIRECTIONCONTROLLER_H
#define PHYDIRECTIONCONTROLLER_H

#include <QWidget>
#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

#define _USE_MATH_DEFINES
#include <math.h>

#include "ValueControllerAdapterIface.h"
#include "Vector.h"

namespace phywidgets
{

class PhyDirectionControllerWidget : public QWidget
{
    Q_OBJECT
  public:
    explicit PhyDirectionControllerWidget( QWidget* parent = nullptr );

    void setDirectionController( VectorControllerAdapterWeakPtr directionControllerWeak );

  private slots:
    void updateTheta( double value );
    void updateAlpha( double value );

  private:
    void configureSpinBox();
    void updateDirectionController();

    static double calculateTheta( const phycoub::Vector& direction );
    static double calculateAlpha( const phycoub::Vector& direction );
    static phycoub::Vector sphereToDirectionCoordinate( double theta, double alpha );

    VectorControllerAdapterWeakPtr directionControllerWeak_;
    double thetaGrad_ = 0.;
    double alphaGrad_ = 0.;

    QHBoxLayout* layout_ = nullptr;

    QVBoxLayout* thetaLayout_ = nullptr;
    QLabel* thetaLabel_ = nullptr;
    QDoubleSpinBox* theta_ = nullptr;

    QVBoxLayout* alphaLayout_ = nullptr;
    QLabel* alphaLabel_ = nullptr;
    QDoubleSpinBox* alpha_ = nullptr;

    constexpr static double radianToGrad_ = 180 / M_PI;
};

} // namespace phywidgets

#endif // PHYDIRECTIONCONTROLLER_H
