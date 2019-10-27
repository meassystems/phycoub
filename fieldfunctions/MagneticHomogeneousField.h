/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 19:23:35
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-27 11:40:57
 */

#include "HomogeneousField.h"
#include "Vector.h"

namespace phycoub
{

class Particle;

class MagneticHomogeneousField : public HomogeneousField
{
  public:
    MagneticHomogeneousField( const Vector& direction, double B );
    virtual ~MagneticHomogeneousField() = default;

    virtual Vector psyField(
        const Vector& mark, const ParticlePtr particle = nullptr ) const override;

    void setMagneticInduction( double B );
    double getMagneticInduction() const;

  private:
    double B_;
};

using MagneticHomogeneousFieldPtr = std::shared_ptr< MagneticHomogeneousField >;

} // namespace phycoub