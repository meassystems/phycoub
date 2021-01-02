/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-24 20:37:03
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 19:00:07
 */

#pragma once

#include "FieldIface.h"

namespace phycoub
{

class LDField : public FieldIface
{
  public:
    LDField( double a, double b, double eps );
    virtual ~LDField() = default;

    virtual Vector psyField(
        const Vector& mark, const ParticlePtr particle = nullptr ) const override;

  private:
    double a_, b_, eps_;
};

using LDFieldPtr = std::shared_ptr< LDField >;

} // namespace phycoub
