/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 22:09:28
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 23:48:34
 */

#include "FeelField.h"

#include <algorithm>
#include <thread>
#include <functional>

#include "CalculationModel.h"

namespace phycoub
{

FeelField::FeelField( CreateFieldBasePtr createField,
    InterworkingFunction* interworkingFunction, std::string fieldName )
    : createField_( createField )
    , interworkingFunction_( interworkingFunction )
    , fieldName_( fieldName )
{
}

void phyCalcInterworkingThread( ParticleGroupList::Iterator begin,
    ParticleGroupList::Iterator end, CreateFieldBasePtr createField,
    InterworkingFunction* interworkingFunction );

void FeelField::phyCalcInterworking()
{
    int numCPU = std::thread::hardware_concurrency() - 2;
    if ( numCPU < 2 || particleGroupList_.getParticleCount() < numCPU * 100 )
    {
        for ( ParticlePtr particle : particleGroupList_ )
        {
            particle->resultant_ += interworkingFunction_->psyForce(
                createField_->getFieldInMark( particle->coordinate_ ), particle );
        }
    }
    else
    {
        size_t sizeBlockOfThread = particleGroupList_.getParticleCount() / numCPU;
        std::thread** threads = new std::thread*[ numCPU ];

        ParticleGroupList::Iterator begin = particleGroupList_.begin();
        ParticleGroupList::Iterator current = begin;

        int currentBlockNumber = 0;
        size_t currentBlockSize = 1;

        while ( currentBlockNumber < numCPU - 1 )
        {
            ++current;
            ++currentBlockSize;
            if ( currentBlockSize == sizeBlockOfThread )
            {
                threads[ currentBlockNumber++ ]
                    = new std::thread( phyCalcInterworkingThread, begin, current,
                        createField_, interworkingFunction_ );
                begin = current;
                currentBlockSize = 1;
            }
        }

        threads[ currentBlockNumber++ ] = new std::thread( phyCalcInterworkingThread,
            begin, particleGroupList_.end(), createField_, interworkingFunction_ );

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

void FeelField::addGroupParticle( ParticleGroupPtr particles )
{
    particleGroupList_.push_back( particles );
}

// Функция потока, для распаралеливания процесса моделировани/
void phyCalcInterworkingThread( ParticleGroupList::Iterator begin,
    ParticleGroupList::Iterator end, CreateFieldBasePtr createField,
    InterworkingFunction* interworkingFunction )
{
    while ( begin != end )
    {
        ParticlePtr particle = *( begin );
        particle->resultant_ += interworkingFunction->psyForce(
            createField->getFieldInMark( particle->coordinate_ ), particle );
        ++begin;
    }
}
//

} // namespace phycoub
