/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-28 16:25:34
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 17:47:10
 */

#include <thread>

#include "InterCommunication.h"

namespace phycoub
{

InterCommunication::InterCommunication( FieldPtr field,
    BorderFieldConditionPtr borderFieldCondition, InterworkingPtr interworking,
    std::string fieldName )
    : InterworkingCalculatorBase( interworking, fieldName )
    , field_( field )
    , borderFieldCondition_( borderFieldCondition )
{
}

// virtual override
void InterCommunication::phyCalcInterworking()
{
    const ParticleGroupList& particleGroupList = getParticleGroupList();
    if ( particleGroupList.getParticleCount() <= 1 )
    {
        return;
    }

    InterworkingPtr interworking = getInterworkingFunction();
    auto endGroup = particleGroupList.cend();

    auto groupIterator = particleGroupList.cbegin();
    auto particleIterator = ( *groupIterator )->begin();

    while ( groupIterator != endGroup )
    {
        if ( particleIterator == ( *groupIterator )->end() )
        {
            ++groupIterator;
            if ( groupIterator == endGroup )
            {
                break;
            }

            particleIterator = ( *groupIterator )->begin();
            continue;
        }

        auto interGroupIterator = groupIterator;
        auto interParticleIterator = particleIterator;
        ++interParticleIterator;

        while ( interGroupIterator != endGroup )
        {
            if ( interParticleIterator == ( *interGroupIterator )->end() )
            {
                ++interGroupIterator;
                if ( interGroupIterator == endGroup )
                {
                    break;
                }

                interParticleIterator = ( *interGroupIterator )->begin();
                continue;
            }

            while ( interParticleIterator != ( *interGroupIterator )->end() )
            {
                ParticlePtr particle = *particleIterator;
                ParticlePtr interParticle = *interParticleIterator;

                const Vector resultant = interworking->psyForce(
                    borderFieldCondition_->phyFieldWithBorderCondition(
                        field_, interParticle, particle->getCoordinate() ),
                    particle );

                particle->resultant_ += resultant;
                interParticle->resultant_ -= resultant;

                ++interParticleIterator;
            }
        }

        ++particleIterator;
    }
}

void InterCommunication::setField( FieldPtr field )
{
    field_ = field;
}

FieldPtr InterCommunication::getFieldCreator()
{
    return field_;
}

} // namespace phycoub