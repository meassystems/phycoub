/*
 * LDInterworking.h
 *
 *  Created on: Dec 17, 2016
 *      Author: root
 */

#ifndef LDINTERWORKING_H_
#define LDINTERWORKING_H_

#include <InterworkingFunction.h>

namespace phycoub {

class LDInterworking: public InterworkingFunction {
public:
	LDInterworking();
	virtual ~LDInterworking();

	const Vector psyForce(const Vector &field, const Particle* particle);
};

} /* namespace phycoub */

#endif /* LDINTERWORKING_H_ */
