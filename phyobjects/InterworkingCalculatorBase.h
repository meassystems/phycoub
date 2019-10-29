/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-28 15:43:54
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-29 14:50:41
 */

#pragma once

#include <memory>
#include <list>

#include "FieldCreator.h"
#include "InterworkingIface.h"
#include "ParticleGroup.h"

namespace phycoub
{

// Interface for calculation interworking force
class InterworkingCalculatorBase
{
  public:
  public:
    InterworkingCalculatorBase( InterworkingPtr interworking, std::string fieldName );
    virtual ~InterworkingCalculatorBase() = default;

    virtual void phyCalcInterworking() = 0;

    void addGroupParticle( ParticleGroupPtr particles );

    void setInterworkingFunction( InterworkingPtr interworkingFunction );
    InterworkingPtr getInterworkingFunction();

  protected:
    const ParticleGroupList& getParticleGroupList();

  private:
    InterworkingPtr interworking_;
    ParticleGroupList particleGroupList_;
    std::string fieldName_;
};

using InterworkingCalculatorPtr = std::shared_ptr< InterworkingCalculatorBase >;
using InterworkingCalculatorList = std::list< InterworkingCalculatorPtr >;

} // namespace phycoub