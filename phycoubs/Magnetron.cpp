/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-08 01:14:14
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-08 01:21:28
 */

#include "Magnetron.h"

namespace phycoub
{

Magnetron::Magnetron()
{
    setDeltaTime( 1E-13 );

    addParticleGroup( electrons_ );

    feelElectricHomogeneousRadialWithCulonInterworking_->addParticleGroup( electrons_ );
    addFieldResponsive( feelElectricHomogeneousRadialWithCulonInterworking_ );

    feelWithMagneticInterworking_->addParticleGroup( electrons_ );
    addFieldResponsive( feelWithMagneticInterworking_ );

    addFieldResponsive( electron2electronInterCommunication_ );

    addLifeTimeController( quantityLifeTimeController_ );

    leapFrogCalculationGroup_->addParticleGroup( electrons_ );
    addCalculationGroup( leapFrogCalculationGroup_ );
}

} // namespace phycoub