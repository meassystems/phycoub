/*
 * ElectronsInElasticCoub.h
 *
 *  Created on: 17 ���. 2016 �.
 *      Author: SFrancishkov
 */

#ifndef ELECTRONSINELASTICCOUB_H_
#define ELECTRONSINELASTICCOUB_H_

#include <CulonInterworking.h>
#include <vector>
#include "ElasticBorder.h"
#include "ElasticCoubCondition.h"
#include "ElectricFieldFunction.h"
#include "Particle.h"
#include "CreateField.h"
#include "FeelField.h"
#include "Vector.h"
#include "CalculationModel.h"
#include "BorderFieldCondition.h"
#include "CyclicBoundedField.h"
#include "HighSpeedModificationVerle.h"

namespace phycoub {
/*
 * Электроны в кристаллической решетке.
 */
class ElectronsInElasticCoub {
public:
	ElectronsInElasticCoub();
	virtual ~ElectronsInElasticCoub();

	void phyCoub();

	double dt_ = 10;
	double e_ = 1.6E-19, mb_ = 9.1E-31, lb_ = 1E-9 , tb_ = 10E-15, vb_ = lb_/tb_;
	Vector borders_{10., 10., 10.};
	double bounds_ = 2.;
	double m_ = 1, z_ = 1.;



	std::vector<Particle> electrons_;
private:
	CalculationModel calculationModel_{CalculationModel()};
	HighSpeedModificationVerle highSpeedModificationVerle_{HighSpeedModificationVerle()};
	ElasticCoubCondition elasticBorder_{&borders_};
	BorderFieldCondition borderFieldCondition_{BorderFieldCondition()};
	CyclicBoundedField cyclicBoundedField{CyclicBoundedField(&bounds_, &borders_)};
	ElectricFieldFunction electricFieldFunction_{e_, mb_, vb_, lb_};
	CulonInterworking culonInterworking_{CulonInterworking()};

	std::vector<CreateField> createField_;
	std::vector<FeelField> feelField_;
};

} /* namespace phycoub */

#endif /* ELECTRONSINELASTICCOUB_H_ */
