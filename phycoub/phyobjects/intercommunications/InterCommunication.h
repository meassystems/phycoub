/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-28 15:41:31
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-08 01:33:44
 */

#pragma once

#include <memory>

#include "InterworkingCalculatorBase.h"
#include "FieldIface.h"
#include "BorderFieldCondition.h"
#include "ThreadPool.h"
#include "SpinLock.h"

namespace phycoub
{

class InterCommunication final : public InterworkingCalculatorBase
{
  public:
    InterCommunication( FieldPtr field, BorderFieldConditionPtr borderFieldCondition,
        InterworkingPtr interworking, std::string fieldName );
    virtual ~InterCommunication() = default;

    virtual void phyCalcInterworking() override;

    void setField( FieldPtr field );
    FieldPtr getFieldCreator();

  private:
    void proceedParticle( ParticleGroupList::ContainerType::const_iterator endGroup,
        ParticleGroupList::ContainerType::const_iterator interGroupIterator,
        ParticleGroup::ContainerType::iterator particleIterator );

    // todo dynamic calibration
    constexpr static size_t numMultithreadingParticleCountThreshold = 100;

    FieldPtr field_;
    BorderFieldConditionPtr borderFieldCondition_;
    ThreadPool _threadPool;
    SpinLock _particleResultantSpinLock;
};

using InterCommunicationPtr = std::shared_ptr< InterCommunication >;

} // namespace phycoub
