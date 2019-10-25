/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-20 00:05:50
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 18:28:23
 */

#pragma once

#include "HomogeneousField.h"

namespace phycoub
{

class Particle;
class Vector;

/*
 * Static Coulomb field
 */
class ElectricHomogeneousField : public HomogeneousField
{
  public:
    ElectricHomogeneousField(
        const Vector& direction, double charge, double epselon = 1. );
    virtual ~ElectricHomogeneousField() = default;

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

} /* namespace phycoub */
