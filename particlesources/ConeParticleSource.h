/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-15 23:05:16
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-16 00:02:40
 */

#pragma once

#include "ParticleSourceBase.h"
#include "ConeShape.h"
#include "RotationMatrix.h"

namespace phycoub
{

class ConeParticleSource
    : public ParticleSourceBase
    , public ConeShape
{
  public:
    ConeParticleSource( const Vector& guideCosines, double heigth, double angle,
        const Vector& sourceCoordinate, const ParticleOptions& particleOptions,
        double energy );
    virtual ~ConeParticleSource() override = default;

    void setGuideCosines( const Vector& guideCosines );
    const Vector& getGuideCosines() const;

    // Implementation of ParticleSourceBase::ParticleSourceIface
    virtual ParticlePtr phyGiveBirthParticle() override;

  private:
    Vector guideCosines_;
    RotationMatrix rotationMatrix_;
};

} // namespace phycoub