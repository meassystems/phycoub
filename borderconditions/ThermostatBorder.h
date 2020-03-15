/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:14:29
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 13:42:45
 */

#pragma once

#include "BorderCondition.h"
#include "CubicShape.h"
#include "Vector.h"
#include "Particle.h"

namespace phycoub
{

class ThermostatBorder
    : public BorderCondition
    , public CubicShape
{
  public:
    ThermostatBorder( const Vector& borders, double kB, double temp );
    virtual ~ThermostatBorder() = default;

    virtual void psyMove(
        const Vector& move, const Vector& speed, ParticlePtr particle ) override;

    void setKb( double kB );
    double getKb() const;

    void setTemperature( double temperature );
    double getTemperature() const;

  private:
    static void temperatureControl( double temp, double kB, double m, Vector* speed );

    double kB_;
    double temperature_;
};

using ThermostatBorderPtr = std::shared_ptr< ThermostatBorder >;

} // namespace phycoub
