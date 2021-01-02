/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 12:09:04
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-10 20:51:14
 */

#include "ElectricField.h"

#define _USE_MATH_DEFINES

#include <math.h>

#include "Constants.h"

namespace phycoub
{

ElectricField::ElectricField( double epselon )
    : epselon_( epselon )
{
    updateFieldConstant();
}

void ElectricField::setEpselon( double epselon )
{
    epselon_ = epselon;
    updateFieldConstant();
}

double ElectricField::getEpselon() const
{
    return epselon_;
}

// virtual override
Vector ElectricField::psyField(
    const Vector& mark, const ParticlePtr particle /* = nullptr*/ ) const
{
    Vector effect;
    Vector distance = ( mark - particle->getCoordinate() );
    if ( distance == 0. )
    {
        return effect;
    }

    effect = distance
        * ( ( fieldConstatnt_ * particle->getOptions().q_ )
              / pow( distance.getModule(), 3 ) );

    return effect;
}

void ElectricField::updateFieldConstant()
{
    fieldConstatnt_ = 1. / ( 4. * M_PI * ElectricConstants::epselon0 * epselon_ );
}

} // namespace phycoub
