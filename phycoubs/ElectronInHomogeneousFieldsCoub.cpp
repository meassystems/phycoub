/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 11:55:14
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-27 13:56:14
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
        Vector( .0, .0, .0 ), ElectricConstants::electronWeight,
        ElectricConstants::electronWeight ) );

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

ParticleGroupPtr ElectronInHomogeneousFieldsCoub::getParticleGroup()
{
    return electrons_;
}

} // namespace phycoub