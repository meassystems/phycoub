/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-29 13:26:16
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-28 23:41:54
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
    const ParticleGroupList& particleGroupList = getParticleGroupList();
    InterworkingPtr interworking = getInterworkingFunction();

    for ( auto groupIterator = particleGroupList.cbegin();
          groupIterator != particleGroupList.cend(); ++groupIterator )
    {
        auto interGroupIterator = groupIterator;
        ++interGroupIterator;

        while ( interGroupIterator != particleGroupList.cend() )
        {
            calculateInterCommunicationFor2Group( *groupIterator, *interGroupIterator );
            ++interGroupIterator;
        }
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

    for ( auto particle : *firstGroup )
    {
        for ( auto interParticle : *secondGroup )
        {
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