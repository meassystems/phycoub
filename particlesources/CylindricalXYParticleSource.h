/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-05 01:17:18
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-10 20:39:38
 */

#pragma once

#include <memory>

#include "ParticleSourceIface.h"
#include "CylindricShape.h"
#include "Vector.h"

namespace phycoub
{

class CylindricalXYPartcleSource
    : public ParticleSourceIface
    , public CylindricShape
{
  public:
    CylindricalXYPartcleSource( double radius, double height, double energy,
        double particleWeight, double particleCharge, const Vector& sourceCoordinate );
    virtual ~CylindricalXYPartcleSource() override = default;

    // Implementation of ParticleSourceIface
    virtual ParticlePtr phyGiveBirthParticle() override;

    void setEnergy( double energy );
    double getEnergy() const;

    void setSourceCordinate( const Vector& sourceCoordinate );
    const Vector& getSourceCoordinate() const;

  private:
    static double generateNormalizedDouble();
    static double getRandomSign();
    static Vector generateXYDirection();

    ParticleOptions particleOptions;

    double energy_ = 0.;
    double speedFactor_ = 0.;
    Vector sourceCoordinate_;
};

using CylindricalXYPartcleSourcePtr = std::shared_ptr< CylindricalXYPartcleSource >;

} // namespace phycoub