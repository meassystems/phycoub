/*
 * CulonInterworking.cpp
 *
 *  Created on: Oct 14, 2016
 *      Author: root
 */

#include <CulonInterworking.h>
#include "math.h"

namespace phycoub {

CulonInterworking::CulonInterworking(){}
CulonInterworking::~CulonInterworking() {}

const Vector CulonInterworking::psyForce(const Vector &field, const Particle* particle) {
	return field * particle->z_;
}

} /* namespace phycoub */
