/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 13:42:50
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-06 01:24:50
 */

#include "PhyCoub.h"

#include <algorithm>

namespace phycoub
{

void PhyCoub::phyCoub()
{
    for ( InterworkingCalculatorPtr& interworkingCalculator :
        interworkingCalculatorList_ )
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

} // namespace phycoub