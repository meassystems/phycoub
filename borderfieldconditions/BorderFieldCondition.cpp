/*
 * BorderFieldCondition.cpp
 *
 *  Created on: 19 ���. 2016 �.
 *      Author: SFrancishkov
 */

#include "BorderFieldCondition.h"
#include <algorithm>
#include "CreateField.h"

namespace phycoub
{

BorderFieldCondition::BorderFieldCondition()
{
}
BorderFieldCondition::~BorderFieldCondition()
{
}

Vector BorderFieldCondition::phySumField( CreateField *createField, const Vector &mark )
{
    Vector result_;

    for_each( createField->particles_.begin(), createField->particles_.end(),
        [&]( const Particle *source ) {
            result_ += createField->functionField_->psyField( *source, mark );
        } );

    return result_;
}

} /* namespace phycoub */
