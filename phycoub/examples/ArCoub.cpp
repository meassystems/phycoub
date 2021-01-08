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
    ParticleGroupPtr argon = std::make_shared< ParticleGroup >();

    setDeltaTime( dt_ );

    const Vector& borders = thermostatBorder_->getBorders();
    for ( int i = 0; i < 400; ++i )
    {
        argon->push_back( std::make_shared< Particle >(
            Vector( ( rand() / (double)RAND_MAX ) * borders.x(),
                ( rand() / (double)RAND_MAX ) * borders.y() * 0.7 + 0.3 * borders.z(),
                ( rand() / (double)RAND_MAX ) * borders.z() ),
            Vector( .0, .0, .0 ), mAr_, z_ ) );
    }

    argonFieldCreator_->addParticleGroup( argon );
    argonFieldCreator_->addParticleGroup( parallelepipedFigure.allParticles_ );
    addContainParticleGroup( argonFieldCreator_ );

    argonFieldResponsive_->addParticleGroup( argon );
    addFieldResponsive( argonFieldResponsive_ );
    addContainParticleGroup( argonFieldResponsive_ );

    leapFrogCalculationGroup_->addParticleGroup( argon );
    addCalculationGroup( leapFrogCalculationGroup_ );
    addContainParticleGroup( leapFrogCalculationGroup_ );
}

const Vector& ArCoub::getBorders() const
{
    return thermostatBorder_->getBorders();
}

} // namespace phycoub
