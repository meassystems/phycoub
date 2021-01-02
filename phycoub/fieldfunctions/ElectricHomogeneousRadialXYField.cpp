/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-11-11 23:14:14
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-10 15:36:26
 */

#include "ElectricHomogeneousRadialXYField.h"

#define _USE_MATH_DEFINES

#include <math.h>

#include "Constants.h"
#include "VectorUtils.h"

namespace phycoub
{

ElectricHomogeneousRadialXYField::ElectricHomogeneousRadialXYField(
    const Vector& center, double radius, double charge, double epselon /* = 1. */ )
    : RadialHomogeneousField( center, radius )
    , charge_( charge )
    , epselon_( epselon )
{
    updateFieldConstant();
}

// virtual override
Vector ElectricHomogeneousRadialXYField::psyField(
    const Vector& mark, const ParticlePtr particle /* = nullptr*/ ) const
{
    const Vector& center = getCenter();
    const Vector centerForMark{ center.x_, center.y_, mark.z_ };
    const Vector notNormalizedDirection = mark - centerForMark;

    if ( notNormalizedDirection.getModule() > getRadius() )
    {
        return Vector{ .0, .0, .0 };
    }

    const Vector resulField
        = VectorUtils::normalizeVector( notNormalizedDirection ) * fieldConstatnt_;
    return resulField;
}

void ElectricHomogeneousRadialXYField::setEpselon( double epselon )
{
    epselon_ = epselon;
    updateFieldConstant();
}

double ElectricHomogeneousRadialXYField::getEpselon() const
{
    return epselon_;
}

void ElectricHomogeneousRadialXYField::setCharge( double charge )
{
    charge_ = charge;
    updateFieldConstant();
}

double ElectricHomogeneousRadialXYField::getCharge() const
{
    return charge_;
}

void ElectricHomogeneousRadialXYField::updateFieldConstant()
{
    fieldConstatnt_ = charge_ / ( 4. * M_PI * ElectricConstants::epselon0 * epselon_ );
}

} // namespace phycoub