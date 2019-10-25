/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 22:09:38
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 21:15:29
 */

#include <CreateField.h>

#include <iterator>
#include <algorithm>

#include "BorderFieldCondition.h"

namespace phycoub
{

CreateField::CreateField( FieldFunction* functionField,
    BorderFieldCondition* borderFieldCondition, const std::string& fieldName )
    : CreateFieldBase( fieldName )
    , functionField_( functionField )
    , borderFieldCondition_( borderFieldCondition )
{
}

Vector CreateField::getFieldInMark( const Vector& mark )
{
    Vector result;
    for ( ParticlePtr particle : particleGroupList_ )
    {
        result += borderFieldCondition_->phyFieldWithBorderCondition(
            functionField_, particle, mark );
    }
    return result;
}

void CreateField::addGroupParticle( ParticleGroupPtr particles )
{
    particleGroupList_.push_back( particles );
}

} // namespace phycoub
