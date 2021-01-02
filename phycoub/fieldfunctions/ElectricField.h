/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 12:08:48
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 19:00:13
 */

#pragma once

#include "FieldIface.h"
#include "Particle.h"

namespace phycoub
{
/*
 * Кулоновское электрическое поле.
 */
class ElectricField : public FieldIface
{
  public:
    explicit ElectricField( double epselon = 1. );
    virtual ~ElectricField() = default;

    Vector psyField(
        const Vector& mark, const ParticlePtr particle = nullptr ) const override;

    void setEpselon( double epselon );
    double getEpselon() const;

  private:
    void updateFieldConstant();

    double epselon_ = 0.;
    double fieldConstatnt_ = 0.;
};

using ElectricFieldPtr = std::shared_ptr< ElectricField >;

} // namespace phycoub
