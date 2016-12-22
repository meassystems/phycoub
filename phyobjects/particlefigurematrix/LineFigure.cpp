/*
 * LineFigure.cpp
 *
 *  Created on: Dec 22, 2016
 *      Author: root
 */

#include <LineFigure.h>

namespace phycoub {

LineFigure::LineFigure(const Vector& direction, const int& num, const Vector& coordinateFerstParticle, const Vector& speed, const double& m, const double& z, BorderCondition* borderCondition): direction_(direction), num_(num) {
	for(int i = 0; i < num_; ++i) {
		particles_.push_back(Particle(coordinateFerstParticle + direction_*i, speed, m, z, borderCondition));
	}
}
LineFigure::~LineFigure() {}

} /* namespace phycoub */
