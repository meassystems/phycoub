/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 13:42:50
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 18:45:18
 */

#include "PhyCoub.h"

#include <algorithm>

namespace phycoub
{

void PhyCoub::phyCoub()
{
    for ( FieldReceiverPtr& fieldResponsive : fieldsResponsive_ )
    {
        fieldResponsive->phyCalcInterworking();
    }
    for ( CalculationGroupPtr calculationGroup : calculationGroups_ )
    {
        calculationGroup->phyModeling( dt_ );
    }
    experimentTime += dt_;
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
    return experimentTime;
}

void PhyCoub::addFieldResponsive( FieldReceiverPtr fieldResponsive )
{
    fieldsResponsive_.push_back( fieldResponsive );
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

} // namespace phycoub