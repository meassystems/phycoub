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

	// http://tm.spbstu.ru/%D0%9F%D0%BE%D1%82%D0%B5%D0%BD%D1%86%D0%B8%D0%B0%D0%BB_%D0%9B%D0%B5%D0%BD%D0%BD%D0%B0%D1%80%D0%B4-%D0%94%D0%B6%D0%BE%D0%BD%D1%81%D0%B0
//	double coef = 12 * eps_ * (pow(a_ / distance.getModule(), 14) - pow(b_ / distance.getModule(), 8));
//	effect = distance * (coef / pow(a_, 2));
	effect = distance * (-24 * eps_ / a_ * (pow(a_ / distance.getModule(), 8) - 2 * pow(b_ / distance.getModule(), 14)));

	return effect;
}

} /* namespace phycoub */
