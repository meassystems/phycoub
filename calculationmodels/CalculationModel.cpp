/*
 * CalculationModel.cpp
 *
 *  Created on: 19 ���. 2016 �.
 *      Author: SFrancishkov
 */

#include "../calculationmodels/CalculationModel.h"

#include <algorithm>
#include "Vector.h"
#include "FeelField.h"
#include "CalculationGroup.h"

namespace phycoub {

CalculationModel::CalculationModel() {}
CalculationModel::~CalculationModel() {}

void CalculationModel::phyCalculate(CalculationGroup* calculationGroup) {
	for_each(calculationGroup->particles_.begin(), calculationGroup->particles_.end(), [&](Particle* particle) {
		particle->speed_ += particle->resultant_ * (*calculationGroup->dt_ / particle->m_);
		particle->move(*calculationGroup->dt_);
	}
	);
}

} /* namespace phycoub */
