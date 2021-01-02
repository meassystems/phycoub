/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-20 00:05:50
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-12 23:09:16
 */

#pragma once

#include "DirectHomogeneousField.h"

namespace phycoub
{

class Particle;
class Vector;

/*
 * Static Coulomb field
 */
class ElectricHomogeneousDirectField : public DirectHomogeneousField
{
  public:
    ElectricHomogeneousDirectField(
        const Vector& direction, double charge, double epselon = 1. );
    virtual ~ElectricHomogeneousDirectField() = default;

    virtual Vector psyField(
        const Vector& mark, const ParticlePtr particle = nullptr ) const override;

    void setEpselon( double epselon );
    double getEpselon() const;

    void setCharge( double charge );
    double getCharge() const;

  private:
    void updateFieldConstant();

    double epselon_ = 1.;
    double charge_ = 0.;
    double fieldConstatnt_ = 0.;
};

using ElectricHomogeneousDirectFieldPtr
    = std::shared_ptr< ElectricHomogeneousDirectField >;

} // namespace phycoub
