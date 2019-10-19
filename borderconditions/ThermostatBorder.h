/*
 * ThermostatBorder.h
 *
 *  Created on: Dec 26, 2016
 *      Author: root
 */

#ifndef THERMOSTATBORDER_H_
#define THERMOSTATBORDER_H_

#include <BorderCondition.h>

#include "Vector.h"
#include "Particle.h"
namespace phycoub
{

class ThermostatBorder : public BorderCondition
{
  public:
    ThermostatBorder( Vector *borders, double *kB, double *temp );
    virtual ~ThermostatBorder();

    virtual void psyMove( const Vector &move, Particle &particle );

  private:
    double *kB_;
    double *temperature_;
};

} /* namespace phycoub */

#endif /* THERMOSTATBORDER_H_ */
