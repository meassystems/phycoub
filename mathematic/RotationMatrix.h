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
    RotationMatrix() = default;
    ~RotationMatrix() = default;

    explicit RotationMatrix( const Vector& cosines );
    void setRotationCosines( const Vector& cosines );
    void setRotationSinuses( const Vector& sinuses );

    void rotateVector( Vector* vector );

  private:
    void updateMatrix( const Vector& cosines, const Vector& sinuses );

#ifndef NDEBUG
  public:
#endif
    Vector cosines_;
    Vector sinuses_;

    Matrix matrix_;
};

} // namespace phycoub