/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 13:42:50
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-12 00:45:28
 */

#include "PhyCoub.h"

#include <algorithm>
#include <unordered_set>

namespace phycoub
{
/*
 * Основной flow.
 * 1) Вычисляем силы действующие на частицы
 * 2) Двигаем частицы
 * 3) Контролируем время жизни
 */
void PhyCoub::phyCoub()
{
    for ( InterworkingCalculatorPtr interworkingCalculator : interworkingCalculatorList_ )
    {
        interworkingCalculator->phyCalcInterworking();
    }
    for ( CalculationGroupPtr calculationGroup : calculationGroups_ )
    {
        calculationGroup->phyModeling( dt_ );
    }
    for ( LifeTimeControllerPtr lifeTimeController : lifeTimeControllers_ )
    {
        lifeTimeController->phyControlLifeTime();
    }
    experimentTime_ += dt_;
}

void PhyCoub::setDeltaTime( double dt )
{
    dt_ = dt;
}

double PhyCoub::getDeltaTime() const
{
    return dt_;
}

double PhyCoub::getExperimentTime() const
{
    return experimentTime_;
}

void PhyCoub::resetToZeroExperimentTime()
{
    experimentTime_ = 0;
}

const ParticleGroupList& PhyCoub::getUniqParticleGroupList()
{
    return uniqParticleGroupList_;
}

void PhyCoub::updateUniqParticleGroupList()
{
    std::unordered_set< IDType > addedGroupIds;
    for ( auto containParticleGroupList : containsParticleGroup_ )
    {
        const ParticleGroupList& particleGroupList
            = containParticleGroupList->getParticleGroupList();

        particleGroupList.forEachGroup( [&addedGroupIds, this]( ParticleGroupPtr group ) {
            const IDType groupId = group->getId();
            if ( addedGroupIds.find( groupId ) == addedGroupIds.end() )
            {
                uniqParticleGroupList_.push_back( group );
                addedGroupIds.emplace( groupId );
            }
        } );
    }
}

ParticleGroupPtr PhyCoub::getGroup( IDType id )
{
    for ( auto group : uniqParticleGroupList_ )
    {
        if ( group->getId() == id )
        {
            return group;
        }
    }

    return nullptr;
}

void PhyCoub::removeGroup( IDType id )
{
    for ( auto containParticleGroupList : containsParticleGroup_ )
    {
        containParticleGroupList->removeParticleGroup( id );
    }
}

void PhyCoub::removeParticle( IDType id )
{
    for ( auto containParticleGroupList : containsParticleGroup_ )
    {
        containParticleGroupList->removeParticle( id );
    }
}

void PhyCoub::addFieldResponsive( InterworkingCalculatorPtr interworkingCalculator )
{
    interworkingCalculatorList_.push_back( interworkingCalculator );
}

void PhyCoub::removeFieldResponsive( std::string id )
{
    // todo
}

void PhyCoub::addCalculationGroup( CalculationGroupPtr calculationGroup )
{
    calculationGroups_.push_back( calculationGroup );
}

void PhyCoub::removeCalculationGroup( std::string id )
{
    // todo
}

void PhyCoub::addLifeTimeController( LifeTimeControllerPtr lifeTimeController )
{
    lifeTimeControllers_.push_back( lifeTimeController );
}

void PhyCoub::removeLifeTimeController( std::string id )
{
    // todo
}

void PhyCoub::addContainParticleGroup( ContainParticleGroupPtr containParticleGroup )
{
    containsParticleGroup_.push_back( containParticleGroup );
}

void PhyCoub::removeContainParticleGroup( std::string id )
{
    // todo
}

} // namespace phycoub