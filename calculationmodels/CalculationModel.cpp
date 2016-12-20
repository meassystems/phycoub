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

namespace phycoub {

CalculationModel::CalculationModel() {}
CalculationModel::~CalculationModel() {}

void CalculationModel::phyCalculate(FeelField* feelField) {
	Vector* interworking = new Vector[feelField->particles_.size()];
	int iterator = 0;

	for_each(feelField->particles_.begin(), feelField->particles_.end(), [&](const Particle* particle) {
		interworking[iterator] = feelField->createField_->getFieldInMark(particle->coordinate_);
		++iterator;
	}
	);

	iterator = 0;
	for_each(feelField->particles_.begin(), feelField->particles_.end(), [&](Particle* particle) {
		particle->speed_ += feelField->interworkingFunction_->psyForce(interworking[iterator], *particle) * (*feelField->dt_ / particle->m_);
		particle->move(*feelField->dt_);
		++iterator;
	}
	);

	delete[] interworking;
}

} /* namespace phycoub */
