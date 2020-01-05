/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-05 01:17:18
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-06 00:42:46
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
    static Vector generateXYDirection();

    double energy_ = 0.;

    // create base class for it
    double particleWeight_ = 0.;
    double particleCharge_ = 0.;
    double speedFactor_ = 0.;
    Vector sourceCoordinate_;
    //
};

} // namespace phycoub