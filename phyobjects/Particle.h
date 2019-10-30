/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 16:28:49
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-30 16:46:06
 */

#pragma once

#include <memory>

#include "Vector.h"

namespace phycoub
{

class BorderCondition;
/*
 * Класс/объект моделируемого пространства - частица.
 */
class Particle
{
  public:
    Particle();
    Particle( const Vector& coordinate, const Vector& speed, double m, double z );
    virtual ~Particle() = default;

    void move( const Vector& coordinate, const Vector& speed );
    const Vector& getCoordinate() const;
    const Vector& getSpeed() const;
    long int getIndex() const;

    bool operator==( const Particle& particle );

    double m_ = 0.;
    double z_ = 0.;
    double potentialEnergy = 0.;

    Vector resultant_;

    Vector previesCoordinate_;
    Vector previesSpeed_;
    Vector previesResultant_;

  private:
    Vector coordinate_;
    Vector speed_;

    static long index;
    long index_;
};

using ParticlePtr = std::shared_ptr< Particle >;

} // namespace phycoub
