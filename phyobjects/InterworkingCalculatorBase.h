/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-28 15:43:54
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-05 23:56:49
 */

#pragma once

#include <memory>
#include <list>

#include "ContainParticleGroupList.h"
#include "FieldCreator.h"
#include "InterworkingIface.h"
#include "ParticleGroup.h"

namespace phycoub
{

// Interface for calculation interworking force
class InterworkingCalculatorBase : public ContainParticleGroupList
{
  public:
  public:
    InterworkingCalculatorBase( InterworkingPtr interworking, std::string fieldName );
    virtual ~InterworkingCalculatorBase() = default;

    virtual void phyCalcInterworking() = 0;

    void setInterworkingFunction( InterworkingPtr interworkingFunction );
    InterworkingPtr getInterworkingFunction();

  private:
    InterworkingPtr interworking_;
    std::string fieldName_;
};

using InterworkingCalculatorPtr = std::shared_ptr< InterworkingCalculatorBase >;
using InterworkingCalculatorList = std::list< InterworkingCalculatorPtr >;

} // namespace phycoub