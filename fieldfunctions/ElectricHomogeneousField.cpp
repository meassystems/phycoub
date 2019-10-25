/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 12:08:09
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 12:21:19
 */

#include "ElectricHomogeneousField.h"

#define _USE_MATH_DEFINES

#include <math.h>

#include "Constants.h"

namespace phycoub
{

ElectricHomogeneousField::ElectricHomogeneousField(
    const Vector& direction, double charge, double epselon /* = 1. */ )
    : HomogeneousField( direction )
    , charge_( charge )
    , epselon_( epselon )
{
    updateFieldConstant();
}

// virtual override
Vector ElectricHomogeneousField::psyField(
    const Vector& mark, const Particle* particle /* = nullptr*/ ) const
{
    const Vector resulField = getDirection() * fieldConstatnt_;
    return resulField;
}

void ElectricHomogeneousField::setEpselon( double epselon )
{
    epselon_ = epselon;
    updateFieldConstant();
}

double ElectricHomogeneousField::getEpselon() const
{
    return epselon_;
}

void ElectricHomogeneousField::setCharge( double charge )
{
    charge_ = charge;
    updateFieldConstant();
}

double ElectricHomogeneousField::getCharge() const
{
    return charge_;
}

void ElectricHomogeneousField::updateFieldConstant()
{
    fieldConstatnt_ = 1. / ( 4. * M_PI * ElectricConstants::epselon0 * epselon_ );
}

} // namespace phycoub