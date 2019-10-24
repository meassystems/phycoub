/*
 * CalculationGroup.h
 *
 *  Created on: Dec 29, 2016
 *      Author: root
 */

#ifndef CALCULATIONGROUP_H_
#define CALCULATIONGROUP_H_

#include <vector>

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

} /* namespace phycoub */

#endif /* CALCULATIONGROUP_H_ */
