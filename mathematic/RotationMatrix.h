/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-10 18:32:39
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 01:29:22
 */

#pragma once

#include "Vector.h"
#include "Matrix.h"

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
    Matrix matrix_;
};

} // namespace phycoub