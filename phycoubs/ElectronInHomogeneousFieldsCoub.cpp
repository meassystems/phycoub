/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 11:55:14
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-01 22:26:33
 */

#include "ElectronInHomogeneousFieldsCoub.h"

#include "FieldReceiver.h"

namespace phycoub
{

ElectronInHomogeneousFieldsCoub::ElectronInHomogeneousFieldsCoub()
{
    setDeltaTime( dt_ );

    const Vector& borders = getBorders();
    electrons_->emplace_back( std::make_shared< Particle >(
        Vector( 0.5 * borders.x_, 0.5 * borders.y_, 0.5 * borders.z_ ),
        Vector( .0, .0, 1. ) * 1e6, ElectricConstants::electronWeight,
        ElectricConstants::electronCharge ) );

    particleGroupList_.push_back( electrons_ );

    feelWithCulonInterworking_->addGroupParticle( electrons_ );
    addFieldResponsive( feelWithCulonInterworking_ );
    feelWithMagneticInterworking_->addGroupParticle( electrons_ );
    addFieldResponsive( feelWithMagneticInterworking_ );

    leapFrogCalculationGroup_->addGroupParticle( electrons_ );
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
    return particleGroupList_;
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

} // namespace phycoub