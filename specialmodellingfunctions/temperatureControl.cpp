/*
 * temperatureControl.cpp
 *
 *  Created on: Dec 26, 2016
 *      Author: root
 */

#include <vector>
#include <math.h>

#include "Vector.h"
#include "Particle.h"

namespace phycoub {

void temperatureControl(const double& temp, const double& kB, int num, std::vector<Particle>* particles, ...) {
	double speedT = .0;
	for (int i = 0; i < num; ++i) {
		for (Particle& particle : *particles) {
			speedT = sqrt((3 * kB * temp) / particle.m_);
			particle.speed_ *= (speedT / particle.speed_.getModule());
		}
		++particles;
	}
}

void temperatureControl(const double& temp, const double& kB, int num, std::vector<Particle*>* particles, ...) {
	double speedT = .0;
	for (int i = 0; i < num; ++i) {
		for (Particle *particle : *particles) {
			speedT = sqrt((3 * kB * temp) / particle->m_);
			particle->speed_ *= (speedT / particle->speed_.getModule());
		}
		++particles;
	}
}

} /* namespace phycoub */

