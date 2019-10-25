/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:14:29
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 22:29:42
 */

#pragma once

#include <BorderCondition.h>

#include "Vector.h"
#include "Particle.h"
namespace phycoub
{

class ThermostatBorder : public BorderCondition
{
  public:
    ThermostatBorder( Vector* borders, double* kB, double* temp );
    virtual ~ThermostatBorder() = default;

    virtual void psyMove( const Vector& move, ParticlePtr* particle ) override;

  private:
    double* kB_;
    double* temperature_;
};

using ThermostatBorderPtr = std::shared_ptr< ThermostatBorder >;

} // namespace phycoub
