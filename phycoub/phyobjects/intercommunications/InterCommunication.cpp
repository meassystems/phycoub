/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-28 16:25:34
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 17:47:10
 */

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
    const size_t particleCount = particleGroupList.getParticleCount();
    size_t particleProcessedCount = particleCount;

    if ( particleGroupList.getParticleCount() <= 1 )
    {
        return;
    }

    std::shared_ptr< std::mutex > particleResultantMutex
        = std::make_shared< std::mutex >();

    BorderFieldConditionPtr borderFieldCondition = borderFieldCondition_;
    FieldPtr field = field_;
    InterworkingPtr interworking = getInterworkingFunction();

    const auto endGroup = particleGroupList.cend();
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

        if ( particleProcessedCount < numMultithreadingParticleCountThreshold )
        {
            proceedParticle( endGroup, groupIterator, particleIterator );
        }
        else
        {
            std::function< void() > task
                = std::bind( &InterCommunication::proceedParticle, this, endGroup,
                    groupIterator, particleIterator );
            _threadPool.pushTask( task );
        }

        --particleProcessedCount;
        ++particleIterator;
    }

    _threadPool.waitAllTaskCompleted();
}

void InterCommunication::setField( FieldPtr field )
{
    field_ = field;
}

FieldPtr InterCommunication::getFieldCreator()
{
    return field_;
}

void InterCommunication::proceedParticle(
    ParticleGroupList::ContainerType::const_iterator endGroup,
    ParticleGroupList::ContainerType::const_iterator interGroupIterator,
    ParticleGroup::ContainerType::iterator particleIterator )
{
    InterworkingPtr interworking = getInterworkingFunction();
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

            {
                std::lock_guard< SpinLock > lock( _particleResultantSpinLock );
                particle->resultant_ += resultant;
                interParticle->resultant_ -= resultant;
            }

            ++interParticleIterator;
        }
    }
}

} // namespace phycoub