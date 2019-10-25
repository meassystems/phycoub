/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 12:08:48
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 18:27:24
 */

#ifndef ELECTRICFIELDFUNCTION_H_
#define ELECTRICFIELDFUNCTION_H_

#include "FieldFunction.h"
#include "Particle.h"

namespace phycoub
{
/*
 * Кулоновское электрическое поле.
 */
class ElectricField : public FieldFunction
{
  public:
    explicit ElectricField( double epselon = 1. );
    virtual ~ElectricField() = default;

    Vector psyField(
        const Vector& mark, const ParticlePtr particle = nullptr ) const override;

    void setEpselon( double epselon );
    double getEpselon() const;

  private:
    void updateFieldConstant();

    double epselon_ = 0.;
    double fieldConstatnt_ = 0.;
};

} /* namespace phycoub */

#endif /* ELECTRICFIELDFUNCTION_H_ */
