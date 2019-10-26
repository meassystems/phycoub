/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 12:14:47
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 10:13:17
 */

#include <LeapFrog.h>

#include <algorithm>
#include <thread>
#include <functional>
#include "Vector.h"
#include "CalculationGroup.h"

namespace phycoub
{

void phyCalculateThreadLP( ParticleGroupList::Iterator begin,
    ParticleGroupList::Iterator end, BorderConditionPtr borderCondition, double dt );

// virtual override
void LeapFrog::phyCalculate(
    BorderConditionPtr borderCondition, double dt, ParticleGroupList* particleGroupList )
{

    int numCPU = std::thread::hardware_concurrency() - 2;
    if ( numCPU < 2 || particleGroupList->getParticleCount() < numCPU * 100 )
    {
        for ( ParticlePtr particle : *particleGroupList )
        {
            particle->speed_ += particle->resultant_ * ( dt / particle->m_ );
            borderCondition->psyMove( particle->speed_ * dt, &particle );
        }
    }
    else
    {
        size_t sizeBlockOfThread = particleGroupList->getParticleCount() / numCPU;
        std::thread** threads = new std::thread*[ numCPU ];

        ParticleGroupList::Iterator begin = particleGroupList->begin();
        ParticleGroupList::Iterator current = begin;

        int currentBlockNumber = 0;
        size_t currentBlockSize = 1;

        while ( currentBlockNumber < numCPU - 1 )
        {
            ++current;
            ++currentBlockSize;
            if ( currentBlockSize == sizeBlockOfThread )
            {
                threads[ currentBlockNumber++ ] = new std::thread(
                    phyCalculateThreadLP, begin, current, borderCondition, dt );
                begin = current;
                currentBlockSize = 1;
            }
        }

        threads[ currentBlockNumber ] = new std::thread(
            phyCalculateThreadLP, begin, particleGroupList->end(), borderCondition, dt );

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
void phyCalculateThreadLP( ParticleGroupList::Iterator begin,
    ParticleGroupList::Iterator end, BorderConditionPtr borderCondition, double dt )
{
    while ( begin != end )
    {
        ( *begin )->speed_ += ( *begin )->resultant_ * ( dt / ( *begin )->m_ );
        borderCondition->psyMove( ( *begin )->speed_ * dt, &*begin );
        ++begin;
    }
}

} // namespace phycoub
