/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-05 01:54:47
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-12 00:42:10
 */

#pragma once

namespace phycoub
{
/*
 * Базовый класс для объектов, которые имеют форму цилиндра
 */
class CylindricShape
{
  public:
    CylindricShape( double radius, double height );
    virtual ~CylindricShape() = default;

    void setRadius( double radius );
    double getRadius() const;

    void setHeight( double height );
    double getHeight() const;

  protected:
    double getDoubleRadius() const;
    double getSquaredRadius() const;

  private:
    double radius_ = 0.;
    double doubleRadius_ = 0.;
    double squaredRadius_ = 0.;
    double height_ = 0.;
};

} // namespace phycoub