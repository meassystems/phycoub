/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 22:09:28
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 19:05:10
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
    : fieldCreator_( fieldCreator )
    , interworking_( interworking )
    , fieldName_( fieldName )
{
}

void phyCalcInterworkingThread( ParticleGroupList::Iterator begin,
    ParticleGroupList::Iterator end, FieldCreatorPtr fieldCreator,
    InterworkingPtr interworkingFunction );

void FieldReceiver::phyCalcInterworking()
{
    int numCPU = std::thread::hardware_concurrency() - 2;
    if ( numCPU < 2 || particleGroupList_.getParticleCount() < numCPU * 100 )
    {
        for ( ParticlePtr particle : particleGroupList_ )
        {
            particle->resultant_ += interworking_->psyForce(
                fieldCreator_->getFieldInMark( particle->getCoordinate() ), particle );
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
                        fieldCreator_, interworking_ );
                begin = current;
                currentBlockSize = 1;
            }
        }

        threads[ currentBlockNumber++ ] = new std::thread( phyCalcInterworkingThread,
            begin, particleGroupList_.end(), fieldCreator_, interworking_ );

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

void FieldReceiver::addGroupParticle( ParticleGroupPtr particles )
{
    particleGroupList_.push_back( particles );
}

void FieldReceiver::setFieldCreator( FieldCreatorPtr fieldCreator )
{
    fieldCreator_ = fieldCreator;
}

FieldCreatorPtr FieldReceiver::getFieldCreator()
{
    return fieldCreator_;
}

void FieldReceiver::setInterworkingFunction( InterworkingPtr interworkingFunction )
{
    interworking_ = interworkingFunction;
}

InterworkingPtr FieldReceiver::getInterworkingFunction()
{
    return interworking_;
}

// Функция потока, для распаралеливания процесса моделировани/
void phyCalcInterworkingThread( ParticleGroupList::Iterator begin,
    ParticleGroupList::Iterator end, FieldCreatorPtr fieldCreator,
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
