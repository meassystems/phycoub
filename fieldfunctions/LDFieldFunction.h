/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-24 20:37:03
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-24 20:47:35
 */

#pragma once

#include <FieldFunction.h>

namespace phycoub
{

class LDFieldFunction : public FieldFunction
{
  public:
    LDFieldFunction( double a, double b, double eps );
    virtual ~LDFieldFunction() = default;

    virtual Vector psyField(
        const Vector& mark, const Particle* particle = nullptr ) const override;

  private:
    double a_, b_, eps_;
};

} // namespace phycoub
