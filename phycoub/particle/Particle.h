/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 16:28:49
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-16 00:58:30
 */

#pragma once

#include <memory>

#include "HasId.h"
#include "Vector.h"
#include "ParticleOptions.h"

namespace phycoub
{

/*
 * Класс/объект моделируемого пространства - частица.
 */
class Particle : public HasId
{
  public:
    Particle();
    Particle( const Vector& coordinate, const Vector& speed, double m, double q );
    Particle( const Vector& coordinate, const Vector& speed, ParticleOptions options );
    virtual ~Particle() = default;

    void move( const Vector& coordinate, const Vector& speed );
    const ParticleOptions& getOptions() const;
    const Vector& getCoordinate() const;
    const Vector& getSpeed() const;

    bool operator==( const Particle& particle );

    double potentialEnergy = 0.;
    Vector resultant_;

    Vector previesSpeed_;
    Vector previesResultant_;

  private:
    ParticleOptions options_;

    Vector coordinate_;
    Vector speed_;
};

using ParticlePtr = std::shared_ptr< Particle >;

} // namespace phycoub
