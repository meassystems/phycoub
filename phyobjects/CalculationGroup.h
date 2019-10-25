/*
 * CalculationGroup.h
 *
 *  Created on: Dec 29, 2016
 *      Author: root
 */

#pragma once

#include <vector>
#include <memory>

#include "Vector.h"
#include "Particle.h"
#include "CalculationModel.h"

namespace phycoub
{

class CalculationGroup
{
  public:
    CalculationGroup( CalculationModel* calculatiomModel, double* dt );
    virtual ~CalculationGroup();

    void phyModeling();

    void addParticle( Particle* particle );
    void addGroupParticle( std::vector< Particle* >& particles );
    void removeParticle( Particle* particle );

    std::vector< Particle* > particles_;
    double* dt_;

  private:
    CalculationModel* calculationModel_;
};

using CalculationGroupPtr = std::shared_ptr< CalculationGroup >;

} // namespace phycoub
