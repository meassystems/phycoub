/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 22:09:38
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-05 23:55:21
 */

#include "DynamicFieldCreator.h"

#include <iterator>
#include <algorithm>

#include "BorderFieldCondition.h"

namespace phycoub
{

DynamicFieldCreator::DynamicFieldCreator( FieldPtr field,
    BorderFieldConditionPtr borderFieldCondition, const std::string& fieldName )
    : FieldCreator( fieldName )
    , field_( field )
    , borderFieldCondition_( borderFieldCondition )
{
}

// virtual override
Vector DynamicFieldCreator::getFieldInMark( const Vector& mark )
{
    Vector result;
    for ( ParticlePtr particle : *getParticleGroupList() )
    {
        result += borderFieldCondition_->phyFieldWithBorderCondition(
            field_, particle, mark );
    }
    return result;
}

void DynamicFieldCreator::setFunctionField( FieldPtr fieldFunction )
{
    field_ = fieldFunction;
}

FieldPtr DynamicFieldCreator::getFieldFunction()
{
    return field_;
}

void DynamicFieldCreator::setBorderFieldCondition(
    BorderFieldConditionPtr borderFieldCondition )
{
    borderFieldCondition_ = borderFieldCondition;
}

BorderFieldConditionPtr DynamicFieldCreator::getBorderFieldCondition()
{
    return borderFieldCondition_;
}

} // namespace phycoub
