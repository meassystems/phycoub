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

double getTemperatureWithoutEnergyTranslationalMotionSystem(const double& kB, const int& num, std::vector<Particle>* particles, ...) {
	double result_ = (getWk(num, particles) - getWkTranslationalMotion(num, particles)) * 2./3./kB;

	return result_;
}
double getTemperatureWithoutEnergyTranslationalMotionSystem(const double& kB, const int& num, std::vector<Particle*>* particles, ...) {
	double result_ = (getWk(num, particles) - getWkTranslationalMotion(num, particles)) * 2./3./kB;

	return result_;
}

double getWk(int num, std::vector<Particle>* particles, ...) {
	double result_ = 0.;
	int numParticles = 0;
	for(int i = 0; i < num; ++ i) {
		for(Particle particle : *particles) {
			result_ += particle.m_ * pow(particle.speed_.getModule(), 2) / 2;
		}
		numParticles += particles->size();
		++particles;
	}

	return result_ / numParticles;
}
double getWk(int num, std::vector<Particle*>* particles, ...) {
	double result_ = 0.;
	int numParticles = 0;
	for(int i = 0; i < num; ++ i) {
		for(Particle* particle : *particles) {
			result_ += particle->m_ * pow(particle->speed_.getModule(), 2) / 2;
		}
		numParticles += particles->size();
		++particles;
	}

	return result_ / numParticles;
}

double getWkTranslationalMotion(int num, std::vector<Particle>* particles, ...) {
	double result_ = 0, mSystem = 0.;
	Vector speedSystem;

	for(int i = 0; i < num; ++i) {
		for(Particle particle: *particles) {
			speedSystem += particle.speed_;
			mSystem += particle.m_;
		}
	}
	result_ = mSystem * pow(speedSystem.getModule(), 2) / 2;

	return result_;
}
double getWkTranslationalMotion(int num, std::vector<Particle*>* particles, ...) {
	double result_ = 0, mSystem = 0.;
	Vector speedSystem;

	for(int i = 0; i < num; ++i) {
		for(Particle* particle: *particles) {
			speedSystem += particle->speed_;
			mSystem += particle->m_;
		}
	}
	result_ = mSystem * pow(speedSystem.getModule(), 2) / 2;

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
