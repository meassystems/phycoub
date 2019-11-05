/*
 * ArCoub.cpp
 *
 *  Created on: 20 дек. 2016 г.
 *      Author: serv
 */

#include <ArCoub.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <time.h>

namespace phycoub
{

ArCoub::ArCoub()
{
    setDeltaTime( dt_ );

    const Vector& borders = thermostatBorder_->getBorders();
    for ( int i = 0; i < 400; ++i )
    {
        argon_->emplace_back( std::make_shared< Particle >(
            Vector( ( rand() / (double)RAND_MAX ) * borders.x_,
                ( rand() / (double)RAND_MAX ) * borders.y_ * 0.7 + 0.3 * borders.z_,
                ( rand() / (double)RAND_MAX ) * borders.z_ ),
            Vector( .0, .0, .0 ), mAr_, z_ ) );
    }

    argonFieldCreator_->addParticleGroup( argon_ );
    argonFieldCreator_->addParticleGroup( parallelepipedFigure.allParticles_ );
    argonFieldResponsive_->addParticleGroup( argon_ );
    addFieldResponsive( argonFieldResponsive_ );

    leapFrogCalculationGroup_->addParticleGroup( argon_ );
    addCalculationGroup( leapFrogCalculationGroup_ );
}

const Vector& ArCoub::getBorders() const
{
    return thermostatBorder_->getBorders();
}

} // namespace phycoub
