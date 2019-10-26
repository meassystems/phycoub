/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 19:23:35
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 10:24:48
 */

#include "HomogeneousField.h"
#include "Vector.h"

namespace phycoub
{

class Particle;

class MagneticHomogeneousField : public HomogeneousField
{
  public:
    MagneticHomogeneousField( const Vector& direction, const Vector& B );
    virtual ~MagneticHomogeneousField() = default;

    virtual Vector psyField(
        const Vector& mark, const ParticlePtr particle = nullptr ) const override;

    void setMagneticInduction( const Vector& B );
    const Vector& getMagneticInduction() const;

  private:
    Vector B_;
};

using MagneticHomogeneousFieldPtr = std::shared_ptr< MagneticHomogeneousField >;

} // namespace phycoub