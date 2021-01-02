/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-15 23:16:59
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 23:36:09
 */

#pragma once

#include "ParticleSourceIface.h"

namespace phycoub
{

class ParticleSourceBase : public ParticleSourceIface
{
  public:
    ParticleSourceBase( const Vector& sourceCoordinate,
        const ParticleOptions& particleOptions, double energy );
    virtual ~ParticleSourceBase() override = default;

    virtual void setSourceCordinate( const Vector& sourceCoordinate );
    const Vector& getSourceCoordinate() const;

    void setParticleOptions( const ParticleOptions& particleOptions );
    const ParticleOptions& getParticleOptions() const;

    void setEnergy( double energy );
    double getEnergy() const;

  protected:
    double getSpeedFactor() const;

  private:
    void updateSpeedFactor();

    Vector sourceCoordinate_;
    ParticleOptions particleOptions_;

    double energy_ = 0.;
    double speedFactor_ = 0.;
};

} // namespace phycoub