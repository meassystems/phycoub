/*
 * FeelField.cpp
 *
 *  Created on: 17 ���. 2016 �.
 *      Author: SFrancishkov
 */

#include <FeelField.h>
#include <algorithm>

#include "../calculationmodels/CalculationModel.h"

namespace phycoub {

FeelField::FeelField(CalculationModel* calculationModel, CreateField* createField ,InterworkingFunction* interworkingFunction, std::string fieldName, double* dt): calculationModel_(calculationModel), createField_(createField), particles_(0), interworkingFunction_(interworkingFunction), fieldName_(fieldName), dt_(dt) {}
FeelField::~FeelField() {}

void FeelField::moveParticles() {
	calculationModel_->phyCalculate(this);
}

void FeelField::addParticle(Particle* particle) {
	particles_.push_back(particle);
}
void FeelField::addGroupParticle(std::vector<Particle> &particles) {
	for_each(particles.begin(), particles.end(), [&](Particle& particle){
		particles_.push_back(&particle);
	});
}
void FeelField::removeParticle(Particle* particle) {
	std::vector<Particle *>::iterator itr = particles_.begin();
	while(itr != particles_.end()) {
		if((*itr)->index == particle->index) {
			particles_.erase(itr);
			break;
		}
		++itr;
	}
}

} /* namespace phycoub */
