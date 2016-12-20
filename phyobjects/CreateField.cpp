/*
 * CreateField.cpp
 *
 *  Created on: 17 ���. 2016 �.
 *      Author: SFrancishkov
 */

#include <CreateField.h>
#include <iterator>
#include <algorithm>
#include "BorderFieldCondition.h"

namespace phycoub {

CreateField::CreateField(FieldFunction* functionField, BorderFieldCondition* borderFieldCondition, std::string fieldName): particles_(0), functionField_(functionField), borderFieldCondition_(borderFieldCondition), fieldName_(fieldName) {}
CreateField::~CreateField() {}

Vector CreateField::getFieldInMark(const Vector& mark) {
	return borderFieldCondition_->phySumField(this, mark);
}

void CreateField::addParticle(Particle* particle) {
	particles_.push_back(particle);
}
void CreateField::addGroupParticle(std::vector<Particle> &particles) {
	for_each(particles.begin(), particles.end(), [&](Particle& particle){
		particles_.push_back(&particle);
	});
}
void CreateField::removeParticle(Particle* particle) {
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
