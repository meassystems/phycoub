/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-11-11 23:14:09
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-08 01:12:01
 */

#pragma once

#include <memory>

#include "RadialHomogeneousField.h"

namespace phycoub
{

// todo rename to ElectricHomogeneousRadiaXYlField
class ElectricHomogeneousRadialField : public RadialHomogeneousField
{
  public:
    ElectricHomogeneousRadialField(
        const Vector& center, double radius, double charge, double epselon = 1. );
    virtual ~ElectricHomogeneousRadialField() override = default;

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

using ElectricHomogeneousRadialFieldPtr
    = std::shared_ptr< ElectricHomogeneousRadialField >;

} // namespace phycoub