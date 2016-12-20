/*
 * measurement.cpp
 *
 *  Created on: 22 ���. 2016 �.
 *      Author: SFrancishkov
 */

#include <vector>
#include <algorithm>
#include <math.h>
#include "Particle.h"

namespace phycoub {

double getWk(std::vector<Particle>& particles) {

	double result_ = 0.;

	for_each(particles.begin(), particles.end(), [&](Particle& particle) {
		result_ += particle.m_ * pow(particle.speed_.getModule(), 2) / 2;
	});

	return result_;
}

double getWp(std::vector<Particle>& particles) {

	double result_ = 0.;

	for_each(particles.begin(), particles.end(), [&](Particle& particle) {
		//result_ += particle.interworking_;
	});

	return result_;
}

}
