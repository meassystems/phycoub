/*
 * ElectricFieldFunction.h
 *
 *  Created on: 17 ���. 2016 �.
 *      Author: SFrancishkov
 */

#ifndef ELECTRICFIELDFUNCTION_H_
#define ELECTRICFIELDFUNCTION_H_

#include "FieldFunction.h"
#include "Particle.h"

namespace phycoub {
/*
 * Кулоновское электрическое поле.
 */
class ElectricFieldFunction: public FieldFunction {
public:
	ElectricFieldFunction(double e, double mb, double vb, double lb);
	virtual ~ElectricFieldFunction();

	Vector psyField(const Particle &source, const Vector &mark);
//	void psyField(const Particle& source, const Particle& mark);

	double e_, mb_, vb_, lb_;
};

} /* namespace phycoub */

#endif /* ELECTRICFIELDFUNCTION_H_ */
