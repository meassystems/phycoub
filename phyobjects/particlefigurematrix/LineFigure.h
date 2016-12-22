/*
 * LineFigure.h
 *
 *  Created on: Dec 22, 2016
 *      Author: root
 */

#ifndef LINEFIGURE_H_
#define LINEFIGURE_H_

#include "Vector.h"
#include "Particle.h"
#include "BorderCondition.h"

#include <vector>

namespace phycoub {

class LineFigure {
public:
	LineFigure(std::vector<Particle*> particles);
	LineFigure(const Vector& direction, const int& num, const Vector& coordinate, const Vector& speed, const double& m, const double& z, BorderCondition* borderCondition);
	virtual ~LineFigure();

	std::vector<Particle*> particles_;
private:
	int num_;
};

} /* namespace phycoub */

#endif /* LINEFIGURE_H_ */
