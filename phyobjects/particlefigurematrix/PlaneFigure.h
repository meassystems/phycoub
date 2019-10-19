/*
 * PlaneFigure.h
 *
 *  Created on: Dec 22, 2016
 *      Author: root
 */

#ifndef PARTICLEFIGUREMATRIX_PLANEFIGURE_H_
#define PARTICLEFIGUREMATRIX_PLANEFIGURE_H_

#include <vector>

#include "Vector.h"
#include "BorderCondition.h"
#include "Particle.h"

namespace phycoub
{

class PlaneFigure
{
  public:
    PlaneFigure( const Vector &directionLine, const Vector &directionPlane,
        const int &numInLine, const int &numLineInPlane, const Vector &coordinate,
        const Vector &speed, const double &m, const double &z,
        BorderCondition *borderCondition );
    virtual ~PlaneFigure();

    std::vector< Particle * > allParticles_;

    std::vector< Particle * > centrallParticles_;
    std::vector< Particle * > borderParticles_;
};

} /* namespace phycoub */

#endif /* PARTICLEFIGUREMATRIX_PLANEFIGURE_H_ */
