/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-10 18:32:39
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-10 19:21:15
 */

#pragma once

#include "Vector.h"

namespace phycoub
{

class RotationMatrix final
{
  public:
    RotationMatrix() = default;
    ~RotationMatrix() = default;

    explicit RotationMatrix( const Vector& theGuideCosines );
    void setGuideCosines( const Vector& theGuideCosines );

    void rotateVector( Vector* vector );

  private:
    void updateMatrix();

    Vector guideCosines_;

    Vector column1_;
    Vector column2_;
    Vector column3_;
};

} // namespace phycoub