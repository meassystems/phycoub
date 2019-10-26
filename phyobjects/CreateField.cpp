/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 22:09:38
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 09:31:15
 */

#include <CreateField.h>

#include <iterator>
#include <algorithm>

#include "BorderFieldCondition.h"

namespace phycoub
{

CreateField::CreateField( FieldFunctionPtr functionField,
    BorderFieldConditionPtr borderFieldCondition, const std::string& fieldName )
    : CreateFieldBase( fieldName )
    , fieldFunction_( functionField )
    , borderFieldCondition_( borderFieldCondition )
{
}

Vector CreateField::getFieldInMark( const Vector& mark )
{
    Vector result;
    for ( ParticlePtr particle : particleGroupList_ )
    {
        result += borderFieldCondition_->phyFieldWithBorderCondition(
            fieldFunction_, particle, mark );
    }
    return result;
}

void CreateField::addGroupParticle( ParticleGroupPtr particles )
{
    particleGroupList_.push_back( particles );
}

void CreateField::setFunctionField( FieldFunctionPtr fieldFunction )
{
    fieldFunction_ = fieldFunction;
}

FieldFunctionPtr CreateField::getFieldFunction()
{
    return fieldFunction_;
}

void CreateField::setBorderFieldCondition( BorderFieldConditionPtr borderFieldCondition )
{
    borderFieldCondition_ = borderFieldCondition;
}

BorderFieldConditionPtr CreateField::getBorderFieldCondition()
{
    return borderFieldCondition_;
}

} // namespace phycoub
