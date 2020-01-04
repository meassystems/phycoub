/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-05 01:17:18
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-05 02:09:37
 */

#pragma once

#include <memory>

#include "ParticleSourceIface.h"
#include "CylindricShape.h"

namespace phycoub
{

class CylindricalPartcleSource
    : public ParticleSourceIface
    , public CylindricShape
{
  public:
    CylindricalPartcleSource( double radius, double height, double energy );
    virtual ~CylindricalPartcleSource() override = default;

    // Implementation of ParticleSourceIface
    virtual void phyGiveBirthParticle() override;

    void setEnergy( double height );
    double getEnergy() const;

  private:
    double energy_ = 0.;
};

} // namespace phycoub