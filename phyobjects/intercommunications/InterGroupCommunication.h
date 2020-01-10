/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-29 13:22:09
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-29 14:26:17
 */

#pragma once

#include <memory>

#include "InterworkingCalculatorBase.h"
#include "FieldIface.h"
#include "BorderFieldCondition.h"
#include "ParticleGroup.h"

namespace phycoub
{

class InterGroupCommunication final : public InterworkingCalculatorBase
{
  public:
    InterGroupCommunication( FieldPtr field, BorderFieldConditionPtr borderFieldCondition,
        InterworkingPtr interworking, std::string fieldName );
    virtual ~InterGroupCommunication() = default;

    virtual void phyCalcInterworking() override;

    void setField( FieldPtr field );
    FieldPtr getFieldCreator();

  private:
    void calculateInterCommunicationFor2Group(
        ParticleGroupPtr firstGroup, ParticleGroupPtr secondGroup );

    FieldPtr field_;
    BorderFieldConditionPtr borderFieldCondition_;
};

using InterGroupCommunicationPtr = std::shared_ptr< InterGroupCommunication >;

} // namespace phycoub