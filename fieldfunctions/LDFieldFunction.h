/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-24 20:37:03
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 09:37:18
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
        const Vector& mark, const ParticlePtr particle = nullptr ) const override;

  private:
    double a_, b_, eps_;
};

using LDFieldFunctionPtr = std::shared_ptr< LDFieldFunction >;

} // namespace phycoub
