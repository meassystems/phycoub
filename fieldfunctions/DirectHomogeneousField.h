/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 18:53:11
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-12 23:08:39
 */

#pragma once

#include "HomogeneousFieldIface.h"
#include "Vector.h"

namespace phycoub
{

class DirectHomogeneousField : public HomogeneousFieldIface
{
  public:
    explicit DirectHomogeneousField( const Vector& direction );
    virtual ~DirectHomogeneousField() = default;

    // Implementation of HomogenousFieldIface
    virtual Vector getDirection( const Vector& mark = Vector{} ) const override;

    void setDirection( const Vector& direction );

  private:
    Vector direction_;
};

} // namespace phycoub