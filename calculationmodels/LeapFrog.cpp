/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 12:14:47
 * @Last Modified by:   Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 12:14:47
 */

#include <LeapFrog.h>

#include <algorithm>
#include <thread>
#include <functional>
#include "Vector.h"
#include "CalculationGroup.h"

namespace phycoub
{

void phyCalculateThreadLP( CalculationGroup* calculationGroup, int start, int end );

void LeapFrog::phyCalculate( CalculationGroup* calculationGroup )
{

    int numCPU = std::thread::hardware_concurrency() - 2;
    if ( numCPU < 2 || (int)calculationGroup->particles_.size() < numCPU * 100 )
    {
        for_each( calculationGroup->particles_.begin(),
            calculationGroup->particles_.end(), [&]( Particle* particle ) {
                particle->speed_
                    += particle->resultant_ * ( *calculationGroup->dt_ / particle->m_ );
                particle->move( *calculationGroup->dt_ );
            } );
    }
    else
    {
        int sizeBlockOfThread = calculationGroup->particles_.size() / numCPU;
        std::thread** threads = new std::thread*[ numCPU ];

        int start = 0, stop = start + sizeBlockOfThread;
        for ( int i = 0; i < numCPU - 1; ++i )
        {
            threads[ i ]
                = new std::thread( phyCalculateThreadLP, calculationGroup, start, stop );
            start = stop;
            stop = start + sizeBlockOfThread;
        }
        threads[ numCPU - 1 ] = new std::thread( phyCalculateThreadLP, calculationGroup,
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
void phyCalculateThreadLP( CalculationGroup* calculationGroup, int start, int end )
{
    for ( int i = start; i < end; ++i )
    {
        calculationGroup->particles_[ i ]->speed_
            += calculationGroup->particles_[ i ]->resultant_
            * ( *calculationGroup->dt_ / calculationGroup->particles_[ i ]->m_ );
        calculationGroup->particles_[ i ]->move( *calculationGroup->dt_ );
    }
}
//

} // namespace phycoub
