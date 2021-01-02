/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 19:23:35
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-08 01:34:16
 */

#pragma once

#include "DirectHomogeneousField.h"
#include "Vector.h"

namespace phycoub
{

class Particle;

class MagneticHomogeneousDirectField : public DirectHomogeneousField
{
  public:
    MagneticHomogeneousDirectField( const Vector& direction, double B );
    virtual ~MagneticHomogeneousDirectField() = default;

    virtual Vector psyField(
        const Vector& mark, const ParticlePtr particle = nullptr ) const override;

    void setMagneticInduction( double B );
    double getMagneticInduction() const;

  private:
    double B_;
};

using MagneticHomogeneousDirectFieldPtr
    = std::shared_ptr< MagneticHomogeneousDirectField >;

} // namespace phycoub