/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 13:13:41
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-09 17:22:31
 */

#pragma once

#include <vector>
#include <string>
#include <memory>

#include "ContainParticleGroupList.h"
#include "InterworkingCalculatorBase.h"
#include "CalculationGroup.h"
#include "LifeTimeControllerIface.h"

namespace phycoub
{

class PhyCoub : public ContainParticleGroupList
{
  public:
    explicit PhyCoub() = default;
    virtual ~PhyCoub() override = default;

    virtual void phyCoub();
    const ParticleGroupList& getParticleGroupList();

    void setDeltaTime( double dt );
    double getDeltaTime() const;

    double getExperimentTime() const;
    void resetToZeroExperimentTime();

  protected:
    void addFieldResponsive( InterworkingCalculatorPtr interworkingCalculator );
    void removeFieldResponsive( std::string id );

    void addCalculationGroup( CalculationGroupPtr calculationGroup );
    void removeCalculationGroup( std::string id );

    void addLifeTimeController( LifeTimeControllerPtr lifeTimeController );
    void removeLifeTimeController( std::string id );

  private:
    double dt_ = 0.;
    double experimentTime_ = 0;

    InterworkingCalculatorList interworkingCalculatorList_;
    CalculationGroupList calculationGroups_;
    LifeTimeControllerList lifeTimeControllers_;
};

using PhyCoubPtr = std::shared_ptr< PhyCoub >;

} // namespace phycoub