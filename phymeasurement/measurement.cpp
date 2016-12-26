/*
 * measurement.cpp
 *
 *  Created on: 22 ���. 2016 �.
 *      Author: SFrancishkov
 */

#include "measurement.h"

#include <algorithm>
#include <math.h>

namespace phycoub {

double getTemperature(const double& kB, const int& num, std::vector<Particle>* particles, ...) {
	double result_ = getWk(num, particles) * 2./3./kB;

	return result_;
}
double getTemperature(const double& kB, const int& num, std::vector<Particle*>* particles, ...) {
	double result_ = getWk(num, particles) * 2./3./kB;

	return result_;
}

double getWk(int num, std::vector<Particle>* particles, ...) {

	double result_ = 0.;
	for(int i = 0; i < num; ++ i) {
		for (Particle particle : *particles) {
			result_ += particle.m_ * pow(particle.speed_.getModule(), 2) / 2;
		}
		result_ /= particles->size();
		++particles;
	}

	return result_;
}
double getWk(int num, std::vector<Particle*>* particles, ...) {

	double result_ = 0.;
	for(int i = 0; i < num; ++ i) {
		for (Particle* particle : *particles) {
			result_ += particle->m_ * pow(particle->speed_.getModule(), 2) / 2;
		}
		result_ /= particles->size();
		++particles;
	}

	return result_;
}
/*
double getWp(std::vector<Particle>& particles) {

	double result_ = 0.;

	for_each(particles.begin(), particles.end(), [&](Particle& particle) {
		//result_ += particle.interworking_;
	});

	return result_;
}
*/
}
