/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-10 18:32:39
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-30 10:42:26
 */

#pragma once

#include "Vector.h"
#include "Matrix.h"

namespace phycoub
{

class RotationMatrix final
{
  public:
    explicit RotationMatrix( const Vector& rotation );
    void rotateVector( Vector* vector );

    static Vector directionToRotation(const Vector& direction);

  private:
    void initMatrix( const Vector& rotation );

    Matrix matrix_;
};

} // namespace phycoub