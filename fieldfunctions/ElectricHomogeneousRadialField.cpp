/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-11-11 23:14:14
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-12 22:40:16
 */

#include "ElectricHomogeneousRadialField.h"

#define _USE_MATH_DEFINES

#include <math.h>

#include "Constants.h"
#include "VectorUtils.h"

namespace phycoub
{

ElectricHomogeneousRadialField::ElectricHomogeneousRadialField(
    const Vector& center, double radius, double charge, double epselon /* = 1. */ )
    : RadialHomogeneousField( center, radius )
    , charge_( charge )
    , epselon_( epselon )
{
    updateFieldConstant();
}

// virtual override
Vector ElectricHomogeneousRadialField::psyField(
    const Vector& mark, const ParticlePtr particle /* = nullptr*/ ) const
{
    const Vector notNormalizedDirection = mark - getCenter();
    if ( notNormalizedDirection.getModule() > getRadius() )
    {
        return Vector{ .0, .0, .0 };
    }

    const Vector resulField
        = VectorUtils::normalizeVector( notNormalizedDirection ) * fieldConstatnt_;
    return resulField;
}

void ElectricHomogeneousRadialField::setEpselon( double epselon )
{
    epselon_ = epselon;
    updateFieldConstant();
}

double ElectricHomogeneousRadialField::getEpselon() const
{
    return epselon_;
}

void ElectricHomogeneousRadialField::setCharge( double charge )
{
    charge_ = charge;
    updateFieldConstant();
}

double ElectricHomogeneousRadialField::getCharge() const
{
    return charge_;
}

void ElectricHomogeneousRadialField::updateFieldConstant()
{
    fieldConstatnt_ = charge_ / ( 4. * M_PI * ElectricConstants::epselon0 * epselon_ );
}

} // namespace phycoub