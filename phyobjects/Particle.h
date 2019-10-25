/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 16:28:49
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 22:48:21
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

    bool operator==( const Particle& particle );

    void moved();

    static long index;
    long index_;
    Vector coordinate_, speed_, resultant_{};
    double m_, z_;

    Vector previesCoordinate_{}, previesSpeed_{}, previesResultant_{};

    double potentialEnergy = 0.;
};

using ParticlePtr = std::shared_ptr< Particle >;

} // namespace phycoub
