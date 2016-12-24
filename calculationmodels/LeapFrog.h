/*
 * LeapFrog.h
 *
 *  Created on: Dec 24, 2016
 *      Author: root
 */

#ifndef LEAPFROG_H_
#define LEAPFROG_H_

#include <CalculationModel.h>

namespace phycoub {

class LeapFrog: public CalculationModel {
public:
	LeapFrog();
	virtual ~LeapFrog();

	virtual void phyCalculate(FeelField* feelField);
};

} /* namespace phycoub */

#endif /* LEAPFROG_H_ */
