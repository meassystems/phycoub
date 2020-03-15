/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-08 01:14:14
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-16 00:39:30
 */

#include "Magnetron.h"

namespace phycoub
{

Magnetron::Magnetron()
{
    initLog();
    initCalculationGroup();
    initElectricField();
    initMagneticField();
    initInterCommunication();
    initElectronSource();
    initWithElectronGroup();

    setDeltaTime( 1E-13 );
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

void Magnetron::initLog()
{
    LogPtr stdErrLog = std::make_shared< Log >();
    StdErrLogObserverPtr stdErrLogObserver = std::make_shared< StdErrLogObserver >();

    setLog( stdErrLog );
    stdErrLog->subsribeForUpdates( stdErrLogObserver );
}

void Magnetron::initCalculationGroup()
{
    cylinderBorderCondition_ = std::make_shared< CylinderBorderCondition >( 1., 1. );
    leapFrog_ = std::make_shared< LeapFrog >();
    leapFrogCalculationGroup_
        = std::make_shared< CalculationGroup >( leapFrog_, cylinderBorderCondition_ );

    addCalculationGroup( leapFrogCalculationGroup_ );
    addContainParticleGroup( leapFrogCalculationGroup_ );
}

void Magnetron::initElectricField()
{
    electricHomogeneousRadialField_
        = std::make_shared< ElectricHomogeneousRadialXYField >(
            Vector{ 1., 1., 0 }, 1., ElectricConstants::electronCharge * 1e16 );

    electricHomogeneousRadialFieldCreator_ = std::make_shared< HomogeneousFieldCreator >(
        electricHomogeneousRadialField_, "ElectricHomogeneousRadialField" );

    culonInterworking_ = std::make_shared< CulonInterworking >();

    feelElectricHomogeneousRadialWithCulonInterworking_
        = std::make_shared< FieldReceiver >( electricHomogeneousRadialFieldCreator_,
            culonInterworking_, "ElectricHomogeneousRadialField CulonInterworking" );

    addFieldResponsive( feelElectricHomogeneousRadialWithCulonInterworking_ );
    addContainParticleGroup( feelElectricHomogeneousRadialWithCulonInterworking_ );
}

void Magnetron::initMagneticField()
{
    magneticHomogeneousDirectField_ = std::make_shared< MagneticHomogeneousDirectField >(
        Vector{ 0., 0., 1. }, 3e-2 );

    magneticHomogeneousDirectFieldCreator_ = std::make_shared< HomogeneousFieldCreator >(
        magneticHomogeneousDirectField_, "MagneticHomogeneousField" );

    magneticInterworking_ = std::make_shared< MagneticInterworking >();

    feelWithMagneticInterworking_
        = std::make_shared< FieldReceiver >( magneticHomogeneousDirectFieldCreator_,
            magneticInterworking_, "Magnetic interworking" );

    addFieldResponsive( feelWithMagneticInterworking_ );
    addContainParticleGroup( feelWithMagneticInterworking_ );
}

void Magnetron::initInterCommunication()
{
    borderFieldCondition_ = std::make_shared< BorderFieldCondition >();
    electricField_ = std::make_shared< ElectricField >();
    interworking_ = std::make_shared< CulonInterworking >();

    electron2electronInterCommunication_
        = std::make_shared< InterCommunication >( electricField_, borderFieldCondition_,
            interworking_, "electron-electron InterCommunication" );

    addFieldResponsive( electron2electronInterCommunication_ );
    addContainParticleGroup( electron2electronInterCommunication_ );
}

void Magnetron::initElectronSource()
{
    ParticleOptions electronOptions(
        ElectricConstants::electronWeight, ElectricConstants::electronCharge );

    cylindricalXYPartcleSource_ = std::make_shared< CylindricalXYPartcleSource >(
        0., 1., Vector{ 1., 1., 0. }, electronOptions, 1e-14 );

    quantityLifeTimeController_ = std::make_shared< QuantityLifeTimeController >(
        10, cylindricalXYPartcleSource_ );

    cylinderBorderCondition_->addBorderReachedObserver( quantityLifeTimeController_ );

    addLifeTimeController( quantityLifeTimeController_ );
    addContainParticleGroup( quantityLifeTimeController_ );
}

void Magnetron::initWithElectronGroup()
{
    ParticleGroupPtr electrons = std::make_shared< ParticleGroup >();
    feelElectricHomogeneousRadialWithCulonInterworking_->addParticleGroup( electrons );
    feelWithMagneticInterworking_->addParticleGroup( electrons );
    electron2electronInterCommunication_->addParticleGroup( electrons );
    leapFrogCalculationGroup_->addParticleGroup( electrons );
    quantityLifeTimeController_->setParticleGroup( electrons );
}

} // namespace phycoub