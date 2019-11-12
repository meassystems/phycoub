/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 11:55:14
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-12 22:48:45
 */

#include "ElectronInHomogeneousFieldsCoub.h"

#include "FieldReceiver.h"

namespace phycoub
{

ElectronInHomogeneousFieldsCoub::ElectronInHomogeneousFieldsCoub()
{
    setDeltaTime( 1E-13 );

    const Vector& borders = getBorders();
    electrons_->emplace_back( std::make_shared< Particle >(
        Vector( 0.5 * borders.x_, 0.5 * borders.y_, 0.5 * borders.z_ ),
        Vector( .0, .0, 1. ) * 1e4, ElectricConstants::electronWeight,
        ElectricConstants::electronCharge ) );

    addParticleGroup( electrons_ );

    feelElectricHomogeneousRadialWithCulonInterworking_->addParticleGroup( electrons_ );
    addFieldResponsive( feelElectricHomogeneousRadialWithCulonInterworking_ );
    feelWithCulonInterworking_->addParticleGroup( electrons_ );
    addFieldResponsive( feelWithCulonInterworking_ );
    feelWithMagneticInterworking_->addParticleGroup( electrons_ );
    addFieldResponsive( feelWithMagneticInterworking_ );

    addFieldResponsive( electron2electronInterCommunication_ );

    leapFrogCalculationGroup_->addParticleGroup( electrons_ );
    addCalculationGroup( leapFrogCalculationGroup_ );
}

const Vector& ElectronInHomogeneousFieldsCoub::getBorders() const
{
    return cyclicBorder_->getBorders();
}

void ElectronInHomogeneousFieldsCoub::setBorders( const Vector& borders )
{
    cyclicBorder_->setBorders( borders );
}

const ParticleGroupList& ElectronInHomogeneousFieldsCoub::getParticleGroupList()
{
    return *ContainParticleGroupList::getParticleGroupList();
}

void ElectronInHomogeneousFieldsCoub::addElectron(
    const Vector& coordinate, const Vector& speed )
{
    electrons_->push_back( std::make_shared< Particle >( coordinate, speed,
        ElectricConstants::electronWeight, ElectricConstants::electronCharge ) );
}

void ElectronInHomogeneousFieldsCoub::removeParticle( long index )
{
    electrons_->remove( index );
}

void ElectronInHomogeneousFieldsCoub::setElectricRadialCenter( const Vector& center )
{
    electricHomogeneousRadialField_->setCenter( center );
}

const Vector& ElectronInHomogeneousFieldsCoub::getElectricRadialCenter() const
{
    return electricHomogeneousRadialField_->getCenter();
}

void ElectronInHomogeneousFieldsCoub::setElectricRadialRadius( double radius )
{
    electricHomogeneousRadialField_->setRadius( radius );
}

double ElectronInHomogeneousFieldsCoub::getElectricRadialRadius() const
{
    return electricHomogeneousRadialField_->getRadius();
}

void ElectronInHomogeneousFieldsCoub::setElectricRadialFieldCharge( double charge )
{
    electricHomogeneousRadialField_->setCharge(
        charge * ElectricConstants::electronCharge );
}

double ElectronInHomogeneousFieldsCoub::getElectricRadialFieldCharge() const
{
    return electricHomogeneousRadialField_->getCharge();
}

void ElectronInHomogeneousFieldsCoub::setElectricFieldDirection( const Vector& direction )
{
    electricHomogeneousField_->setDirection( direction );
}

const Vector& ElectronInHomogeneousFieldsCoub::getElectricFieldDirection() const
{
    return electricHomogeneousField_->getDirection();
}

void ElectronInHomogeneousFieldsCoub::setElectricFieldCharge( double charge )
{
    electricHomogeneousField_->setCharge( charge * ElectricConstants::electronCharge );
}

double ElectronInHomogeneousFieldsCoub::getElectricFieldCharge() const
{
    return electricHomogeneousField_->getCharge();
}

void ElectronInHomogeneousFieldsCoub::setMagneticFieldDirection( const Vector& direction )
{
    magneticHomogeneousField_->setDirection( direction );
}

const Vector& ElectronInHomogeneousFieldsCoub::getMagneticFieldDirection() const
{
    return magneticHomogeneousField_->getDirection();
}

void ElectronInHomogeneousFieldsCoub::setMagneticFieldInduction( double B )
{
    magneticHomogeneousField_->setMagneticInduction( B );
}

double ElectronInHomogeneousFieldsCoub::getMagneticFieldInduction() const
{
    return magneticHomogeneousField_->getMagneticInduction();
}

void ElectronInHomogeneousFieldsCoub::switchElectron2ElectronInterworking( bool flag )
{
    if ( flag )
    {
        electron2electronInterCommunication_->addParticleGroup( electrons_ );
    }
    else
    {
        electron2electronInterCommunication_->removeParticleGroup( electrons_ );
    }
}

} // namespace phycoub