/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-11-11 23:15:56
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-12 22:37:34
 */

#pragma once

#include "FieldIface.h"

namespace phycoub
{

class RadialHomogeneousField : public FieldIface
{

  public:
    RadialHomogeneousField( const Vector& center, double radius );
    virtual ~RadialHomogeneousField() = default;

    Vector getDirection( const Vector& mark ) const;

    void setCenter( const Vector& center );
    const Vector& getCenter() const;

    double getRadius() const;
    void setRadius( double radius );

  private:
    Vector center_;
    double radius_;
};

} // namespace phycoub