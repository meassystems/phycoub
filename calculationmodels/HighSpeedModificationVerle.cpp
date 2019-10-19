/*
 * HighSpeedModificationVerle.cpp
 *
 *  Created on: Oct 20, 2016
 *      Author: root
 */

#include <HighSpeedModificationVerle.h>
#include <algorithm>
#include <thread>
#include <functional>
#include "Vector.h"
#include "CalculationGroup.h"

namespace phycoub
{

HighSpeedModificationVerle::HighSpeedModificationVerle()
{
}
HighSpeedModificationVerle::~HighSpeedModificationVerle()
{
}

void phyCalculateThread( CalculationGroup *calculationGroup, int start, int end );

void HighSpeedModificationVerle::phyCalculate( CalculationGroup *calculationGroup )
{

    int numCPU = std::thread::hardware_concurrency() - 2;
    if ( numCPU < 2 || (int)calculationGroup->particles_.size() < numCPU * 100 )
    {
        for_each( calculationGroup->particles_.begin(),
            calculationGroup->particles_.end(), [&]( Particle *particle ) {
                particle->move( particle->previesSpeed_ * ( *calculationGroup->dt_ )
                    + particle->previesResultant_ * pow( *calculationGroup->dt_, 2 )
                        / ( 2 * particle->m_ ) );
                particle->speed_ += ( particle->resultant_ + particle->previesResultant_ )
                    * ( *calculationGroup->dt_ / ( particle->m_ * 2 ) );
            } );
    }
    else
    {
        int sizeBlockOfThread = calculationGroup->particles_.size() / numCPU;
        std::thread **threads = new std::thread *[ numCPU ];

        int start = 0, stop = start + sizeBlockOfThread;
        for ( int i = 0; i < numCPU - 1; ++i )
        {
            threads[ i ]
                = new std::thread( phyCalculateThread, calculationGroup, start, stop );
            start = stop;
            stop = start + sizeBlockOfThread;
        }
        threads[ numCPU - 1 ] = new std::thread( phyCalculateThread, calculationGroup,
            start, calculationGroup->particles_.size() );

        for ( int i = 0; i < numCPU; ++i )
        {
            if ( threads[ i ]->joinable() )
            {
                threads[ i ]->join();
            }
        }
        for ( int i = 0; i < numCPU; ++i )
        {
            delete threads[ i ];
        }
        delete[] threads;
    }
}

// Функция потока, для распаралеливания процесса моделировани/
void phyCalculateThread( CalculationGroup *calculationGroup, int start, int end )
{
    for ( int i = start; i < end; ++i )
    {
        calculationGroup->particles_[ i ]->move(
            calculationGroup->particles_[ i ]->previesSpeed_ * ( *calculationGroup->dt_ )
            + calculationGroup->particles_[ i ]->previesResultant_
                * pow( *calculationGroup->dt_, 2 )
                / ( 2 * calculationGroup->particles_[ i ]->m_ ) );
        calculationGroup->particles_[ i ]->speed_
            += ( calculationGroup->particles_[ i ]->resultant_
                   + calculationGroup->particles_[ i ]->previesResultant_ )
            * ( *calculationGroup->dt_ / ( calculationGroup->particles_[ i ]->m_ * 2 ) );
    }
}
//

} /* namespace phycoub */
