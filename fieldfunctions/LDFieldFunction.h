/*
 * LDFieldFunction.h
 *
 *  Created on: Dec 17, 2016
 *      Author: root
 */

#ifndef LDFIELDFUNCTION_H_
#define LDFIELDFUNCTION_H_

#include <FieldFunction.h>

namespace phycoub {

class LDFieldFunction: public FieldFunction {
	double a_, b_, eps_;
public:
	LDFieldFunction(double a, double b, double eps);
	virtual ~LDFieldFunction();

	virtual Vector psyField(const Particle& source, const Vector& mark);
};

} /* namespace phycoub */

#endif /* LDFIELDFUNCTION_H_ */
