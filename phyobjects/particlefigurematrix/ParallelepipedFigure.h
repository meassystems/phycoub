/*
 * ParallelepipedFigure.h
 *
 *  Created on: Dec 28, 2016
 *      Author: root
 */

#ifndef PARTICLEFIGUREMATRIX_PARALLELEPIPEDFIGURE_H_
#define PARTICLEFIGUREMATRIX_PARALLELEPIPEDFIGURE_H_

#include <vector>

#include "Vector.h"
#include "BorderCondition.h"
#include "Particle.h"

namespace phycoub {

class ParallelepipedFigure {
public:
	ParallelepipedFigure(const Vector& directionLine, const Vector& directionPlane, const Vector& directionParallelepiped, const int& numInLine, const int& numLineInPlane, const int& numPlaneInParallelepiped, const Vector& coordinate, const Vector& speed, const double& m, const double& z, BorderCondition* borderCondition);
	virtual ~ParallelepipedFigure();

	std::vector<Particle*> allParticles_;

	std::vector<Particle*> centrallParticles_;
	std::vector<Particle*> borderParticles_;
};

} /* namespace phycoub */

#endif /* PARTICLEFIGUREMATRIX_PARALLELEPIPEDFIGURE_H_ */
