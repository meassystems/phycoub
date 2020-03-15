/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 11:55:14
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-16 01:07:05
 */

#include "ElectronInHomogeneousFieldsCoub.h"

#include "FieldReceiver.h"
#include "ParticleOptionsCatalog.h"

namespace phycoub
{

ElectronInHomogeneousFieldsCoub::ElectronInHomogeneousFieldsCoub()
{
    initLog();
    initCalculationGroup();
    initElectricField();
    initMagneticField();
    initInterCommunication();
    initWithElectronGroup();

    setDeltaTime( 1E-13 );
    updateUniqParticleGroupList();
}

Vector ElectronInHomogeneousFieldsCoub::getBorders() const
{
    return cyclicBorder_->getBorders();
}

void ElectronInHomogeneousFieldsCoub::setBorders( Vector borders )
{
    cyclicBorder_->setBorders( borders );
}

void ElectronInHomogeneousFieldsCoub::addElectron(
    const Vector& coordinate, const Vector& speed, const ParticleOptions& options )
{
    ParticleGroupPtr electrons = getGroup( electronGroupId_ );
    electrons->push_back( std::make_shared< Particle >( coordinate, speed, options ) );
}

void ElectronInHomogeneousFieldsCoub::setElectricFieldDirection( Vector direction )
{
    electricHomogeneousDirectField_->setDirection( direction );
}

Vector ElectronInHomogeneousFieldsCoub::getElectricFieldDirection() const
{
    return electricHomogeneousDirectField_->getDirection();
}

void ElectronInHomogeneousFieldsCoub::setElectricFieldCharge( double charge )
{
    electricHomogeneousDirectField_->setCharge(
        charge * ElectricConstants::electronCharge );
}

double ElectronInHomogeneousFieldsCoub::getElectricFieldCharge() const
{
    return electricHomogeneousDirectField_->getCharge();
}

void ElectronInHomogeneousFieldsCoub::setMagneticFieldDirection( Vector direction )
{
    magneticHomogeneousDirectField_->setDirection( direction );
}

Vector ElectronInHomogeneousFieldsCoub::getMagneticFieldDirection() const
{
    return magneticHomogeneousDirectField_->getDirection();
}

void ElectronInHomogeneousFieldsCoub::setMagneticFieldInduction( double B )
{
    magneticHomogeneousDirectField_->setMagneticInduction( B );
}

double ElectronInHomogeneousFieldsCoub::getMagneticFieldInduction() const
{
    return magneticHomogeneousDirectField_->getMagneticInduction();
}

void ElectronInHomogeneousFieldsCoub::setElectron2ElectronInterworkingFlag( bool flag )
{
    electron2ElectronInterworkingFlag = flag;
    if ( electron2ElectronInterworkingFlag )
    {
        ParticleGroupPtr electrons = getGroup( electronGroupId_ );
        electron2electronInterCommunication_->addParticleGroup( electrons );
    }
    else
    {
        electron2electronInterCommunication_->removeParticleGroup( electronGroupId_ );
    }
}

bool ElectronInHomogeneousFieldsCoub::getElectron2ElectronInterworkingFlag() const
{
    return electron2ElectronInterworkingFlag;
}

void ElectronInHomogeneousFieldsCoub::initLog()
{
    stdErrLog = std::make_shared< Log >();
    stdErrLogObserver = std::make_shared< StdErrLogObserver >();

    setLog( stdErrLog );
    stdErrLog->subsribeForUpdates( stdErrLogObserver );
}

void ElectronInHomogeneousFieldsCoub::initCalculationGroup()
{
    constexpr static double borderSize_ = 1.e-4;
    cyclicBorder_ = std::make_shared< CyclicBorder >( Vector{ borderSize_ } );
    cyclicBorder_->setLog( stdErrLog );

    leapFrog_ = std::make_shared< LeapFrog >();
    leapFrogCalculationGroup_
        = std::make_shared< CalculationGroup >( leapFrog_, cyclicBorder_ );

    addCalculationGroup( leapFrogCalculationGroup_ );
    addContainParticleGroup( leapFrogCalculationGroup_ );
}

void ElectronInHomogeneousFieldsCoub::initElectricField()
{

    culonInterworking_ = std::make_shared< CulonInterworking >();

    electricHomogeneousDirectField_ = std::make_shared< ElectricHomogeneousDirectField >(
        Vector{ 0, 0, 1 }, ElectricConstants::electronCharge * 0 );
    electricHomogeneousDirectFieldCreator_ = std::make_shared< HomogeneousFieldCreator >(
        electricHomogeneousDirectField_, "ElectricHomogeneousField" );
    feelElectricHomogeneousDirectWithCulonInterworking_
        = std::make_shared< FieldReceiver >( electricHomogeneousDirectFieldCreator_,
            culonInterworking_, "CulonInterworking" );

    addFieldResponsive( feelElectricHomogeneousDirectWithCulonInterworking_ );
    addContainParticleGroup( feelElectricHomogeneousDirectWithCulonInterworking_ );
}

void ElectronInHomogeneousFieldsCoub::initMagneticField()
{
    magneticHomogeneousDirectField_
        = std::make_shared< MagneticHomogeneousDirectField >( Vector{ 0, 1, 1 }, 3e-2 );
    magneticHomogeneousDirectFieldCreator_ = std::make_shared< HomogeneousFieldCreator >(
        magneticHomogeneousDirectField_, "MagneticHomogeneousField" );
    magneticInterworking_ = std::make_shared< MagneticInterworking >();
    feelWithMagneticInterworking_
        = std::make_shared< FieldReceiver >( magneticHomogeneousDirectFieldCreator_,
            magneticInterworking_, "MagneticInterworking" );

    addFieldResponsive( feelWithMagneticInterworking_ );
    addContainParticleGroup( feelWithMagneticInterworking_ );
}

void ElectronInHomogeneousFieldsCoub::initInterCommunication()
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

void ElectronInHomogeneousFieldsCoub::initWithElectronGroup()
{

    ParticleGroupPtr electrons = std::make_shared< ParticleGroup >();
    electronGroupId_ = electrons->getId();

    const Vector& borders = getBorders();
    ParticleOptions electronOptions = ParticleOptionsCatalog::getElectronOptions();

    electrons->push_back( std::make_shared< Particle >(
        Vector( 0.5 * borders.x_, 0.5 * borders.y_, 0.5 * borders.z_ ),
        Vector( .0, .0, 1. ) * 1e4, electronOptions ) );

    feelElectricHomogeneousDirectWithCulonInterworking_->addParticleGroup( electrons );
    feelWithMagneticInterworking_->addParticleGroup( electrons );
    leapFrogCalculationGroup_->addParticleGroup( electrons );
}

} // namespace phycoub