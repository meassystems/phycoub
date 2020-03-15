/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-15 22:38:55
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 23:01:16
 */

#pragma once

namespace phycoub
{

class ConeShape
{
  public:
    ConeShape( double height, double angle );
    virtual ~ConeShape() = default;

    void setHeight( double height );
    double getHeight() const;

    void setAngle( double angle );
    double getAngle() const;

    void setRadius( double radius );
    double getRadius() const;

  private:
    void updateRadius();
    void updateAngle();

    double height_ = 0.;
    double angle_ = 0.;
    double radius_ = 0.;
};

} // namespace phycoub