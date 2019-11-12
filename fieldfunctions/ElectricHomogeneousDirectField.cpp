/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 12:08:09
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-12 23:10:03
 */

#include "ElectricHomogeneousDirectField.h"

#define _USE_MATH_DEFINES

#include <math.h>

#include "Constants.h"

namespace phycoub
{

ElectricHomogeneousDirectField::ElectricHomogeneousDirectField(
    const Vector& direction, double charge, double epselon /* = 1. */ )
    : DirectHomogeneousField( direction )
    , charge_( charge )
    , epselon_( epselon )
{
    updateFieldConstant();
}

// virtual override
Vector ElectricHomogeneousDirectField::psyField(
    const Vector& mark, const ParticlePtr particle /* = nullptr*/ ) const
{
    const Vector resulField = getDirection() * fieldConstatnt_;
    return resulField;
}

void ElectricHomogeneousDirectField::setEpselon( double epselon )
{
    epselon_ = epselon;
    updateFieldConstant();
}

double ElectricHomogeneousDirectField::getEpselon() const
{
    return epselon_;
}

void ElectricHomogeneousDirectField::setCharge( double charge )
{
    charge_ = charge;
    updateFieldConstant();
}

double ElectricHomogeneousDirectField::getCharge() const
{
    return charge_;
}

void ElectricHomogeneousDirectField::updateFieldConstant()
{
    fieldConstatnt_ = charge_ / ( 4. * M_PI * ElectricConstants::epselon0 * epselon_ );
}

} // namespace phycoub