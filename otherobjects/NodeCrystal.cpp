/*
 * NodeCrystal.cpp
 *
 *  Created on: Oct 14, 2016
 *      Author: root
 */

#include "NodeCrystal.h"

namespace phycoub {

NodeCrystal::NodeCrystal(): Particle(), shag(0) {
	++index;
}
NodeCrystal::NodeCrystal(const Vector& coordinate, const Vector& speed, double m, double q,
		BorderCondition* borderCondition): Particle(coordinate, speed, m, q, borderCondition), shag(0) {
			++index;
		}
NodeCrystal::~NodeCrystal() {}

} /* namespace phycoub */
