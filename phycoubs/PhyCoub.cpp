/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 13:42:50
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 15:29:05
 */

#include "PhyCoub.h"

#include <algorithm>

namespace phycoub
{

PhyCoub::PhyCoub( double dt )
    : dt_( dt )
{
}

void PhyCoub::phyCoub()
{
    for_each( fieldsResponsive_.begin(), fieldsResponsive_.end(),
        []( FeelFieldPtr& feelFie ) { feelFie->phyCalcInterworking(); } );
    for_each( calculationGroups_.begin(), calculationGroups_.end(),
        []( CalculationGroupPtr& calculationGroup ) {
            calculationGroup->phyModeling();
        } );

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

void PhyCoub::addFieldResponsive( FeelFieldPtr fieldResponsive )
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