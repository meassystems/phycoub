/*
 * ArCoub.h
 *
 *  Created on: 20 дек. 2016 г.
 *      Author: serv
 */

#ifndef ARCOUB_H_
#define ARCOUB_H_

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

class ArCoub {
public:
	ArCoub();
	virtual ~ArCoub();

	void phyCoub();

	double dt_ = 1E-14, k_ = 1.38E-23, z_ = 0.;
	Vector borders_{aAr*20};
	Vector* bounds_{};
	double mAr_ = 6.6E-26, epsAr = 1.67E-21, aAr = 3.4-10;

	std::vector<Particle> azot_;
	std::vector<Particle> oxygen_;
private:
	ElasticCoubCondition elasticBorder_{&borders_};
	BorderFieldCondition borderFieldCondition_{BorderFieldCondition()};
	HighSpeedModificationVerle highSpeedModificationVerle_{HighSpeedModificationVerle()};

	LDFieldFunction argonField_{aAr, aAr, epsAr};
	LDInterworking argontInterworking;


	std::vector<CreateField> createField_;
	std::vector<FeelField> feelField_;

};

} /* namespace phycoub */

#endif /* ARCOUB_H_ */
