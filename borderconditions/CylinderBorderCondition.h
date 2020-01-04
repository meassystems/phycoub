/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-04 14:06:27
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-04 14:42:34
 */

#pragma once

#include "BorderCondition.h"
#include "BorderReachedEventGenerator.h"

namespace phycoub
{

class CylinderBorderCondition
    : public BorderCondition
    , public BorderReachedEventGenerator
{
  public:
    CylinderBorderCondition( double radius, double height );
    virtual ~CylinderBorderCondition() override = default;

    // Implementation of BorderCondition
    virtual void psyMove(
        const Vector& move, const Vector& speed, ParticlePtr* particle ) override;

    void setRadius( double radius );
    double getRadius() const;

    void setHeight( double height );
    double getHeight() const;

  private:
    double radius_ = 0.;
    double doubleRadius_ = 0.;
    double squaredRadius_ = 0.;
    double height_ = 0.;
};

} // namespace phycoub