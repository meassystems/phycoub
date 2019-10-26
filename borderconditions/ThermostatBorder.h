/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:14:29
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 08:44:35
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
    ThermostatBorder( const Vector& borders, double kB, double temp );
    virtual ~ThermostatBorder() = default;

    virtual void psyMove( const Vector& move, ParticlePtr* particle ) override;

    void setKb( double kB );
    double getKb() const;

    void setTemperature( double temperature );
    double getTemperature() const;

  private:
    static void temperatureControl( double temp, double kB, ParticlePtr* particle );

    double kB_;
    double temperature_;
};

using ThermostatBorderPtr = std::shared_ptr< ThermostatBorder >;

} // namespace phycoub
