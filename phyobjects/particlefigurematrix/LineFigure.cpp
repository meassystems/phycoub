/*
 * LineFigure.cpp
 *
 *  Created on: Dec 22, 2016
 *      Author: root
 */

#include <LineFigure.h>

namespace phycoub {
LineFigure::LineFigure(std::vector<Particle*> particles): particles_(particles) {}
LineFigure::LineFigure(const Vector& direction, const int& num, const Vector& coordinateFerstParticle, const Vector& speed, const double& m, const double& z, BorderCondition* borderCondition) {
	for(int i = 0; i < num; ++i) {
		particles_.push_back(new Particle(coordinateFerstParticle + direction*i, speed, m, z, borderCondition));
	}
}
LineFigure::~LineFigure() {
	for(unsigned int i = 0; i < particles_.size(); ++i) {
		delete particles_[i];
	}
	particles_.clear();
}

} /* namespace phycoub */
