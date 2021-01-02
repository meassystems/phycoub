/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-11-11 23:15:56
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-12 00:38:21
 */

#pragma once

#include "HomogeneousFieldIface.h"

namespace phycoub
{
/*
 * Базовый класс для радиального гомогенного поля
 */
class RadialHomogeneousField : public HomogeneousFieldIface
{

  public:
    RadialHomogeneousField( const Vector& center, double radius );
    virtual ~RadialHomogeneousField() = default;

    // Implementation of HomogeneousFieldIface
    virtual Vector getDirection( const Vector& mark ) const override;

    void setCenter( const Vector& center );
    const Vector& getCenter() const;

    double getRadius() const;
    void setRadius( double radius );

  private:
    Vector center_;
    double radius_;
};

} // namespace phycoub