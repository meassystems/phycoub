/*
 * temperatureControl.cpp
 *
 *  Created on: Dec 26, 2016
 *      Author: root
 */

#include "temperatureControl.h"

namespace phycoub {

void temperatureControl(const double& temp, const double& kB, Particle& particle) {
	double speedT = sqrt((3 * kB * temp) / particle.m_);
	particle.speed_ *= (speedT / particle.speed_.getModule());
}
void temperatureControl(const double& temp, const double& kB, Particle* particle) {
	double speedT = sqrt((3 * kB * temp) / particle->m_);
	particle->speed_ *= (speedT / particle->speed_.getModule());
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

