/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-29 13:26:16
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-06 00:01:44
 */

#include <thread>

#include "InterGroupCommunication.h"

namespace phycoub
{

InterGroupCommunication::InterGroupCommunication( FieldPtr field,
    BorderFieldConditionPtr borderFieldCondition, InterworkingPtr interworking,
    std::string fieldName )
    : InterworkingCalculatorBase( interworking, fieldName )
    , field_( field )
    , borderFieldCondition_( borderFieldCondition )
{
}

// virtual override
void InterGroupCommunication::phyCalcInterworking()
{
    const ParticleGroupList& particleGroupList = *getParticleGroupList();
    InterworkingPtr interworking = getInterworkingFunction();

    int numCPU = std::thread::hardware_concurrency() - 2;
    if ( /*numCPU < 2 || particleGroupList.getParticleCount() < numCPU * 100*/ true )
    {

        for ( ParticleGroupList::GroupConstIterator groupIterator
              = particleGroupList.beginGroup();
              groupIterator != particleGroupList.endGroup(); )
        {
            ParticleGroupPtr particleGroup = *groupIterator;
            for ( ParticleGroupList::GroupConstIterator interGroupIterator
                  = ++groupIterator;
                  interGroupIterator != particleGroupList.endGroup();
                  ++interGroupIterator )
            {
                calculateInterCommunicationFor2Group(
                    particleGroup, *interGroupIterator );
            }
        }

        for ( ParticlePtr particle : particleGroupList )
        {
            particle->resultant_ += interworking->psyForce(
                field_->psyField( particle->getCoordinate(), particle ), particle );
        }
    }
    else
    {
    }
}

void InterGroupCommunication::setField( FieldPtr field )
{
    field_ = field;
}

FieldPtr InterGroupCommunication::getFieldCreator()
{
    return field_;
}

void InterGroupCommunication::calculateInterCommunicationFor2Group(
    ParticleGroupPtr firstGroup, ParticleGroupPtr secondGroup )
{
    InterworkingPtr interworking = getInterworkingFunction();

    for ( ParticleGroup::iterator particleIterator = firstGroup->begin();
          particleIterator != firstGroup->end(); ++particleIterator )
    {
        ParticlePtr particle = *particleIterator;
        for ( ParticleGroup::iterator interParticleIterator = secondGroup->begin();
              interParticleIterator != secondGroup->end(); ++interParticleIterator )
        {
            ParticlePtr interParticle = *interParticleIterator;
            const Vector resultant = interworking->psyForce(
                borderFieldCondition_->phyFieldWithBorderCondition(
                    field_, interParticle, particle->getCoordinate() ),
                particle );

            particle->resultant_ += resultant;
            interParticle->resultant_ -= resultant;
        }
    }
}

} // namespace phycoub