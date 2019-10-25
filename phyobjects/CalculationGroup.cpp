/*
 * CalculationGroup.cpp
 *
 *  Created on: Dec 29, 2016
 *      Author: root
 */

#include <CalculationGroup.h>

#include <algorithm>

namespace phycoub
{

CalculationGroup::CalculationGroup( CalculationModel* calculatiomModel, double* dt )
    : calculationModel_( calculatiomModel )
    , dt_( dt )
{
}
CalculationGroup::~CalculationGroup()
{
}

void CalculationGroup::phyModeling()
{
    calculationModel_->phyCalculate( this );
}

void CalculationGroup::addParticle( Particle* particle )
{
    particles_.push_back( particle );
}
void CalculationGroup::addGroupParticle( std::vector< Particle* >& particles )
{
    for_each( particles.begin(), particles.end(),
        [&]( Particle* particle ) { particles_.push_back( particle ); } );
}
void CalculationGroup::removeParticle( Particle* particle )
{
    std::vector< Particle* >::iterator itr = particles_.begin();
    while ( itr != particles_.end() )
    {
        if ( ( *itr )->index == particle->index )
        {
            particles_.erase( itr );
            break;
        }
        ++itr;
    }
}

} /* namespace phycoub */
