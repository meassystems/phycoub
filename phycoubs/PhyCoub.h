/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 13:13:41
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 13:44:59
 */

#pragma once

#include <vector>
#include <string>
#include <memory>

#include "ContainParticleGroupIface.h"
#include "InterworkingCalculatorBase.h"
#include "CalculationGroup.h"
#include "LifeTimeControllerIface.h"

namespace phycoub
{

class PhyCoub
{
  public:
    PhyCoub() = default;
    virtual ~PhyCoub() = default;

    virtual void phyCoub();

    void setDeltaTime( double dt );
    double getDeltaTime() const;

    double getExperimentTime() const;
    void resetToZeroExperimentTime();

    ParticleGroupList getUniqParticleGroupList();
    void updateUniqParticleGroupList();

    ParticleGroupPtr getGroup( IDType id );

    void removeGroup( IDType id );
    void removeParticle( IDType id );

  protected:
    void addFieldResponsive( InterworkingCalculatorPtr interworkingCalculator );
    void removeFieldResponsive( std::string id );

    void addCalculationGroup( CalculationGroupPtr calculationGroup );
    void removeCalculationGroup( std::string id );

    void addLifeTimeController( LifeTimeControllerPtr lifeTimeController );
    void removeLifeTimeController( std::string id );

    void addContainParticleGroup( ContainParticleGroupPtr containParticleGroup );
    void removeContainParticleGroup( std::string id );

  private:
    double dt_ = 0.;
    double experimentTime_ = 0;

    InterworkingCalculatorList interworkingCalculatorList_;
    CalculationGroupList calculationGroups_;
    LifeTimeControllerList lifeTimeControllers_;
    ContainParticleGroupPtrList containsParticleGroup_;

    ParticleGroupList uniqParticleGroupList_;
};

using PhyCoubPtr = std::shared_ptr< PhyCoub >;

} // namespace phycoub