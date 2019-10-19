/*
 * NodeCrystal.h
 *
 *  Created on: Oct 14, 2016
 *      Author: root
 */

#ifndef NODECRYSTAL_H_
#define NODECRYSTAL_H_

#include "Particle.h"

namespace phycoub
{

class NodeCrystal : public Particle
{
  public:
    NodeCrystal();
    NodeCrystal( const Vector &coordinate, const Vector &speed, double m, double q,
        BorderCondition *borderCondition );
    virtual ~NodeCrystal();

    long shag;
};

} /* namespace phycoub */

#endif /* NODECRYSTAL_H_ */
