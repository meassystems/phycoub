/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 22:09:28
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 12:38:24
 */

#include "FeelField.h"

#include <algorithm>
#include <thread>
#include <functional>

#include "CalculationModel.h"

namespace phycoub
{

FeelField::FeelField( CreateFieldBasePtr fieldCreator,
    InterworkingFunctionPtr interworkingFunction, std::string fieldName )
    : fieldCreator_( fieldCreator )
    , interworkingFunction_( interworkingFunction )
    , fieldName_( fieldName )
{
}

void phyCalcInterworkingThread( ParticleGroupList::Iterator begin,
    ParticleGroupList::Iterator end, CreateFieldBasePtr fieldCreator,
    InterworkingFunctionPtr interworkingFunction );

void FeelField::phyCalcInterworking()
{
    int numCPU = std::thread::hardware_concurrency() - 2;
    if ( numCPU < 2 || particleGroupList_.getParticleCount() < numCPU * 100 )
    {
        for ( ParticlePtr particle : particleGroupList_ )
        {
            particle->resultant_ += interworkingFunction_->psyForce(
                fieldCreator_->getFieldInMark( particle->coordinate_ ), particle );
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
                        fieldCreator_, interworkingFunction_ );
                begin = current;
                currentBlockSize = 1;
            }
        }

        threads[ currentBlockNumber++ ] = new std::thread( phyCalcInterworkingThread,
            begin, particleGroupList_.end(), fieldCreator_, interworkingFunction_ );

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

void FeelField::setFieldCreator( CreateFieldBasePtr fieldCreator )
{
    fieldCreator_ = fieldCreator;
}

CreateFieldBasePtr FeelField::getFieldCreator()
{
    return fieldCreator_;
}

void FeelField::setInterworkingFunction( InterworkingFunctionPtr interworkingFunction )
{
    interworkingFunction_ = interworkingFunction;
}

InterworkingFunctionPtr FeelField::getInterworkingFunction()
{
    return interworkingFunction_;
}

// Функция потока, для распаралеливания процесса моделировани/
void phyCalcInterworkingThread( ParticleGroupList::Iterator begin,
    ParticleGroupList::Iterator end, CreateFieldBasePtr fieldCreator,
    InterworkingFunctionPtr interworkingFunction )
{
    while ( begin != end )
    {
        ParticlePtr particle = *( begin );
        particle->resultant_ += interworkingFunction->psyForce(
            fieldCreator->getFieldInMark( particle->coordinate_ ), particle );
        ++begin;
    }
}

} // namespace phycoub
