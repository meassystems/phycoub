/*
 * LDFieldFunction.cpp
 *
 *  Created on: Dec 17, 2016
 *      Author: root
 */

#include <LDFieldFunction.h>

#include <math.h>

namespace phycoub {

LDFieldFunction::LDFieldFunction(double a, double b, double eps): a_(a), b_(b), eps_(eps) {}
LDFieldFunction::~LDFieldFunction() {}

Vector LDFieldFunction::psyField(const Particle& source, const Vector& mark) {
	Vector effect;
	Vector distance = (mark - source.coordinate_);
	if(distance == 0.) {
		return effect;
	}

	effect = distance * (-24 * eps_ / pow(a_, 2) * (pow(a_ / distance.getModule(), 8) - 2 * pow(b_ / distance.getModule(), 14)));

	return effect;
}

} /* namespace phycoub */
