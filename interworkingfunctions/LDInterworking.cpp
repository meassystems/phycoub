/*
 * LDInterworking.cpp
 *
 *  Created on: Dec 17, 2016
 *      Author: root
 */

#include <LDInterworking.h>

namespace phycoub {

LDInterworking::LDInterworking() {}
LDInterworking::~LDInterworking() {}

const Vector LDInterworking::psyForce(const Vector &field, Particle particle) {
	return field;
}

} /* namespace phycoub */
