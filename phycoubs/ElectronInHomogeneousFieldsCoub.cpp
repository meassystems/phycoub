/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 11:55:14
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-18 22:46:51
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

    feelElectricHomogeneousDirectWithCulonInterworking_->addParticleGroup( electrons_ );
    addFieldResponsive( feelElectricHomogeneousDirectWithCulonInterworking_ );
    feelWithMagneticInterworking_->addParticleGroup( electrons_ );
    addFieldResponsive( feelWithMagneticInterworking_ );

    addFieldResponsive( electron2electronInterCommunication_ );

    leapFrogCalculationGroup_->addParticleGroup( electrons_ );
    addCalculationGroup( leapFrogCalculationGroup_ );
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
    electrons_->push_back( std::make_shared< Particle >( coordinate, speed, options ) );
}

void ElectronInHomogeneousFieldsCoub::removeParticle( long index )
{
    electrons_->remove( index );
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
        electron2electronInterCommunication_->addParticleGroup( electrons_ );
    }
    else
    {
        electron2electronInterCommunication_->removeParticleGroup( electrons_ );
    }
}

bool ElectronInHomogeneousFieldsCoub::getElectron2ElectronInterworkingFlag() const
{
    return electron2ElectronInterworkingFlag;
}

} // namespace phycoub