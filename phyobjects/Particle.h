/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 16:28:49
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-10 20:41:36
 */

#pragma once

#include <memory>

#include "HasId.h"
#include "Vector.h"

namespace phycoub
{

struct ParticleOptions final
{
    ParticleOptions() = default;
    ParticleOptions( double m, double q );

    double m_ = 0.;
    double q_ = 0.;
};

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

    Vector previesCoordinate_;
    Vector previesSpeed_;
    Vector previesResultant_;

  private:
    ParticleOptions options_;

    Vector coordinate_;
    Vector speed_;
};

using ParticlePtr = std::shared_ptr< Particle >;

} // namespace phycoub
