/*
 * measurement.h
 *
 *  Created on: Dec 26, 2016
 *      Author: root
 */

#ifndef MEASUREMENT_H_
#define MEASUREMENT_H_

#include <vector>

#include "Particle.h"

namespace phycoub {

double getTemperature(const double& kB, const int& num, std::vector<Particle>* particles, ...);
double getTemperature(const double& kB, const int& num, std::vector<Particle*>* particles, ...);

double getWk(int num, std::vector<Particle>* particles, ...);
double getWk(int num, std::vector<Particle*>* particles, ...);

}

#endif /* MEASUREMENT_H_ */
