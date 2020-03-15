/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-05 01:17:18
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 23:52:17
 */

#pragma once

#include <memory>

#include "ParticleSourceBase.h"
#include "CylindricShape.h"
#include "Vector.h"

namespace phycoub
{
/*
 * Цилиндрический источник частиц в плоскости XY. Рождает частицы в цилиндре, направленные
 * из его центра
 */
class CylindricalXYPartcleSource
    : public ParticleSourceBase
    , public CylindricShape
{
  public:
    CylindricalXYPartcleSource( double radius, double height,
        const Vector& sourceCoordinate, const ParticleOptions& particleOptions,
        double energy );
    virtual ~CylindricalXYPartcleSource() override = default;

    // Implementation of ParticleSourceBase
    virtual void setSourceCordinate( const Vector& sourceCoordinate ) override;

    // Implementation of ParticleSourceBase::ParticleSourceIface
    virtual ParticlePtr phyGiveBirthParticle() override;
};

using CylindricalXYPartcleSourcePtr = std::shared_ptr< CylindricalXYPartcleSource >;

} // namespace phycoub