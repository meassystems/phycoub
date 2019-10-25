/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:33:13
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 23:14:49
 */

#pragma once

#include "Particle.h"

namespace phycoub
{

class NodeCrystal : public Particle
{
  public:
    NodeCrystal();
    NodeCrystal( const Vector& coordinate, const Vector& speed, double m, double q );
    virtual ~NodeCrystal() = default;

    long shag;
};

} // namespace phycoub
