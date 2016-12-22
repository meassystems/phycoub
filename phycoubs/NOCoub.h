/*
 * NOCoub.h
 *
 *  Created on: Dec 17, 2016
 *      Author: root
 */

#ifndef NOCOUB_H_
#define NOCOUB_H_

#include <vector>

#include "Vector.h"
#include "Particle.h"
#include "CreateField.h"
#include "FeelField.h"

#include "ElasticCoubCondition.h"
#include "BorderFieldCondition.h"
#include "HighSpeedModificationVerle.h"
#include "LDFieldFunction.h"
#include "LDInterworking.h"

namespace phycoub {

class NOCoub {
public:
	NOCoub();
	virtual ~NOCoub();

	void phyCoub();

	double dt_ = 1E-15, k_ = 1.38E-23, z_ = 0.;
	Vector borders_{1E-8, 1E-8, 1E-8};
	double mN_ = 23.24E-27, epsN = 95.05*k_, aN = 3.698E-10;
	double mO_ = 13.28E-27, epsO = 117.5*k_, aO = 3.58E-10;
	double epsNO = 131.*k_, aNO = 3.17E-10;

	std::vector<Particle> azot_;
	std::vector<Particle> oxygen_;
private:
	ElasticCoubCondition elasticBorder_{&borders_};
	BorderFieldCondition borderFieldCondition_{BorderFieldCondition()};
	HighSpeedModificationVerle highSpeedModificationVerle_{HighSpeedModificationVerle()};

	LDFieldFunction azotField_{aN, aN, epsN};
	LDInterworking azotInterworking;
	LDFieldFunction oxygenField_{aO, aO, epsO};
	LDInterworking oxygenInterworking;

	LDFieldFunction NOField_{aNO, aNO, epsO};
	LDInterworking NOInterworking{};

	std::vector<CreateField> createField_;
	std::vector<FeelField> feelField_;

};

} /* namespace phycoub */

#endif /* NOCOUB_H_ */
