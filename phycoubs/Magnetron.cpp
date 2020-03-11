/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-08 01:14:14
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 12:34:09
 */

#include "Magnetron.h"

namespace phycoub
{

Magnetron::Magnetron()
{
    ParticleGroupPtr electrons_ = std::make_shared< ParticleGroup >();
    cylindricalXYPartcleSource_ = std::make_shared< CylindricalXYPartcleSource >( 0., 1.,
        1e-14, ElectricConstants::electronWeight, ElectricConstants::electronCharge,
        Vector{ 1., 1., 0. } );
    quantityLifeTimeController_ = std::make_shared< QuantityLifeTimeController >(
        10, electrons_, cylindricalXYPartcleSource_ );

    setDeltaTime( 1E-13 );

    feelElectricHomogeneousRadialWithCulonInterworking_->addParticleGroup( electrons_ );
    addFieldResponsive( feelElectricHomogeneousRadialWithCulonInterworking_ );
    addContainParticleGroup( feelElectricHomogeneousRadialWithCulonInterworking_ );

    feelWithMagneticInterworking_->addParticleGroup( electrons_ );
    addFieldResponsive( feelWithMagneticInterworking_ );
    addContainParticleGroup( feelWithMagneticInterworking_ );

    addFieldResponsive( electron2electronInterCommunication_ );

    cylinderBorderCondition_->addBorderReachedObserver( quantityLifeTimeController_ );
    addLifeTimeController( quantityLifeTimeController_ );

    leapFrogCalculationGroup_->addParticleGroup( electrons_ );
    addCalculationGroup( leapFrogCalculationGroup_ );
    addContainParticleGroup( leapFrogCalculationGroup_ );

    updateUniqParticleGroupList();
}

double Magnetron::getRadius() const
{
    return cylinderBorderCondition_->getRadius();
}

void Magnetron::setRadius( double radius )
{
    cylinderBorderCondition_->setRadius( radius );
    cylindricalXYPartcleSource_->setSourceCordinate( Vector{ radius, radius, 0 } );
}

double Magnetron::getHeight() const
{
    return cylinderBorderCondition_->getHeight();
}

void Magnetron::setHeigtht( double height )
{
    cylinderBorderCondition_->setHeight( height );
}

double Magnetron::getElectricRadialFieldCharge() const
{
    return electricHomogeneousRadialField_->getCharge()
        / ElectricConstants::electronCharge;
}

void Magnetron::setElectricRadialFieldCharge( double charge )
{
    electricHomogeneousRadialField_->setCharge(
        charge * ElectricConstants::electronCharge );
}

double Magnetron::getMagneticFieldInduction() const
{
    return magneticHomogeneousDirectField_->getMagneticInduction();
}

void Magnetron::setMagneticFieldInduction( double B )
{
    magneticHomogeneousDirectField_->setMagneticInduction( B );
}

double Magnetron::getEnergy() const
{
    return cylindricalXYPartcleSource_->getEnergy();
}

void Magnetron::setEnergy( double energy )
{
    cylindricalXYPartcleSource_->setEnergy( energy );
}

long Magnetron::getLifeParticleCount() const
{
    return quantityLifeTimeController_->getLifeParticleCount();
}

void Magnetron::setLifeParticleCount( long count )
{
    quantityLifeTimeController_->setLifeParticleCount( count );
}

} // namespace phycoub