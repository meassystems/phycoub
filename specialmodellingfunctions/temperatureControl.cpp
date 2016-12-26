/*
 * temperatureControl.cpp
 *
 *  Created on: Dec 26, 2016
 *      Author: root
 */

#include <vector>

#include "Vector.h"
#include "Particle.h"

namespace phycoub {

void temperatureControl(const double& temp, int num, std::vector<Particle>* particles, ...) {
	for(int i = 0; i < num; ++i) {
		for(Particle& particle : *particles) {
			particle.speed_.x_ = 0.0;
			particle.speed_.y_ = 0.0;
			particle.speed_.z_ = 0.0;
		}
		++particles;
	}
}

} /* namespace phycoub */


