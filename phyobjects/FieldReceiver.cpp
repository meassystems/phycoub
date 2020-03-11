/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 22:09:28
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 16:51:16
 */

#include <algorithm>
#include <thread>
#include <functional>

#include "FieldReceiver.h"
#include "CalculationModel.h"

namespace phycoub
{

FieldReceiver::FieldReceiver(
    FieldCreatorPtr fieldCreator, InterworkingPtr interworking, std::string fieldName )
    : InterworkingCalculatorBase( interworking, fieldName )
    , fieldCreator_( fieldCreator )
{
}

// virtual override
void FieldReceiver::phyCalcInterworking()
{
    const ParticleGroupList& particleGroupList = getParticleGroupList();
    InterworkingPtr interworking = getInterworkingFunction();

    particleGroupList.forEachParticle( [this, interworking]( ParticlePtr particle ) {
        particle->resultant_ += interworking->psyForce(
            fieldCreator_->getFieldInMark( particle->getCoordinate() ), particle );
    } );
}

void FieldReceiver::setFieldCreator( FieldCreatorPtr fieldCreator )
{
    fieldCreator_ = fieldCreator;
}

FieldCreatorPtr FieldReceiver::getFieldCreator()
{
    return fieldCreator_;
}

} // namespace phycoub
