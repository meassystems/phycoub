/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-28 16:25:34
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-06 00:01:52
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
    const ParticleGroupList& particleGroupList = *getParticleGroupList();
    InterworkingPtr interworking = getInterworkingFunction();

    int numCPU = std::thread::hardware_concurrency() - 2;
    if ( /*numCPU < 2 || particleGroupList.getParticleCount() < numCPU * 100*/ true )
    {

        for ( ParticleGroupList::ParticleConstIterator particleIterator
              = particleGroupList.begin();
              particleIterator != particleGroupList.end(); )
        {
            ParticlePtr particle = *particleIterator;
            for ( ParticleGroupList::ParticleConstIterator interParticleIterator
                  = ++particleIterator;
                  interParticleIterator != particleGroupList.end();
                  ++interParticleIterator )
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

void InterCommunication::setField( FieldPtr field )
{
    field_ = field;
}

FieldPtr InterCommunication::getFieldCreator()
{
    return field_;
}

} // namespace phycoub