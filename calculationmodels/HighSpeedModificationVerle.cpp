/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-26 10:13:55
 * @Last Modified by:   Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 10:13:55
 */

#include <HighSpeedModificationVerle.h>
#include <algorithm>
#include <thread>
#include <functional>
#include "Vector.h"
#include "CalculationGroup.h"

namespace phycoub
{

void phyCalculateThread( ParticleGroupList::Iterator begin,
    ParticleGroupList::Iterator end, BorderConditionPtr borderCondition, double dt );

// virtual override
void HighSpeedModificationVerle::phyCalculate(
    BorderConditionPtr borderCondition, double dt, ParticleGroupList* particleGroupList )
{
    int numCPU = std::thread::hardware_concurrency() - 2;
    if ( numCPU < 2 || particleGroupList->getParticleCount() < numCPU * 100 )
    {
        for ( ParticlePtr particle : *particleGroupList )
        {
            const Vector speed = particle->getSpeed()
                + ( particle->resultant_ + particle->previesResultant_ )
                    * ( dt / ( particle->m_ * 2 ) );

            borderCondition->psyMove( particle->previesSpeed_ * dt
                    + particle->previesResultant_ * pow( dt, 2 ) / ( 2 * particle->m_ ),
                speed, &particle );
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
                    phyCalculateThread, begin, current, borderCondition, dt );
                begin = current;
                currentBlockSize = 1;
            }
        }

        threads[ currentBlockNumber ] = new std::thread(
            phyCalculateThread, begin, particleGroupList->end(), borderCondition, dt );

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
} // namespace phycoub

// Функция потока, для распаралеливания процесса моделировани/
void phyCalculateThread( ParticleGroupList::Iterator begin,
    ParticleGroupList::Iterator end, BorderConditionPtr borderCondition, double dt )
{
    while ( begin != end )
    {
        const Vector speed = ( *begin )->getSpeed()
            + ( ( *begin )->resultant_ + ( *begin )->previesResultant_ )
                * ( dt / ( ( *begin )->m_ * 2 ) );

        borderCondition->psyMove( ( *begin )->previesSpeed_ * ( dt )
                + ( *begin )->previesResultant_ * pow( dt, 2 ) / ( 2 * ( *begin )->m_ ),
            speed, &*begin );
        ++begin;
    }
}
//

} // namespace phycoub
