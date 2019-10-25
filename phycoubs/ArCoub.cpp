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

#include "temperatureControl.h"

namespace phycoub
{

ArCoub::ArCoub()
    : PhyCoub( dt_ )
{
    for ( int i = 0; i < 400; ++i )
    {
        argon_.push_back( new Particle(
            Vector( ( rand() / (double)RAND_MAX ) * borders_.x_,
                ( rand() / (double)RAND_MAX ) * borders_.y_ * 0.7 + 0.3 * borders_.z_,
                ( rand() / (double)RAND_MAX ) * borders_.z_ ),
            Vector( .0, .0, .0 ), mAr_, z_, &thermostatBorder ) );
    }

    argonFieldCreator_->addGroupParticle( argon_ );
    argonFieldCreator_->addGroupParticle( parallelepipedFigure.allParticles_ );
    argonFieldResponsive_->addGroupParticle( argon_ );
    addFieldResponsive( argonFieldResponsive_ );

    leapFrogCalculationGroup_->addGroupParticle( argon_ );
    addCalculationGroup( leapFrogCalculationGroup_ );
}

ArCoub::~ArCoub()
{
    for ( Particle* particle : argon_ )
    {
        delete particle;
    }
    argon_.clear();
}

} // namespace phycoub
