/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 22:09:28
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-05 23:58:58
 */

#include <algorithm>
#include <thread>
#include <functional>

#include "FieldReceiver.h"
#include "CalculationModel.h"

namespace phycoub
{

FieldReceiver::FieldReceiver(
    FieldCreatorPtr fieldCreator, InterworkingPtr interworking, std::string fieldName )
    : InterworkingCalculatorBase( interworking, fieldName )
    , fieldCreator_( fieldCreator )
{
}

void phyCalcInterworkingThread( ParticleGroupList::ParticleConstIterator begin,
    ParticleGroupList::ParticleConstIterator end, FieldCreatorPtr fieldCreator,
    InterworkingPtr interworkingFunction );

// virtual override
void FieldReceiver::phyCalcInterworking()
{
    const ParticleGroupList& particleGroupList = *getParticleGroupList();
    InterworkingPtr interworking = getInterworkingFunction();

    int numCPU = std::thread::hardware_concurrency() - 2;
    if ( numCPU < 2 || particleGroupList.getParticleCount() < numCPU * 100 )
    {
        for ( ParticlePtr particle : particleGroupList )
        {
            particle->resultant_ += interworking->psyForce(
                fieldCreator_->getFieldInMark( particle->getCoordinate() ), particle );
        }
    }
    else
    {
        size_t sizeBlockOfThread = particleGroupList.getParticleCount() / numCPU;
        std::thread** threads = new std::thread*[ numCPU ];

        ParticleGroupList::ParticleConstIterator begin = particleGroupList.begin();
        ParticleGroupList::ParticleConstIterator current = begin;

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
                        fieldCreator_, interworking );
                begin = current;
                currentBlockSize = 1;
            }
        }

        threads[ currentBlockNumber++ ] = new std::thread( phyCalcInterworkingThread,
            begin, particleGroupList.end(), fieldCreator_, interworking );

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

void FieldReceiver::setFieldCreator( FieldCreatorPtr fieldCreator )
{
    fieldCreator_ = fieldCreator;
}

FieldCreatorPtr FieldReceiver::getFieldCreator()
{
    return fieldCreator_;
}

// Функция потока, для распаралеливания процесса моделировани/
void phyCalcInterworkingThread( ParticleGroupList::ParticleConstIterator begin,
    ParticleGroupList::ParticleConstIterator end, FieldCreatorPtr fieldCreator,
    InterworkingPtr interworkingFunction )
{
    while ( begin != end )
    {
        ParticlePtr particle = *( begin );
        particle->resultant_ += interworkingFunction->psyForce(
            fieldCreator->getFieldInMark( particle->getCoordinate() ), particle );
        ++begin;
    }
}

} // namespace phycoub
