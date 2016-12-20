/*
 * ElectronsInElasticCoub.cpp
 *
 *  Created on: 17 ���. 2016 �.
 *      Author: SFrancishkov
 */

#include "ElectronsInElasticCoub.h"
#include <algorithm>
#include <math.h>

namespace phycoub {

ElectronsInElasticCoub::ElectronsInElasticCoub() {
	createField_.push_back(CreateField(&electricFieldFunction_, &borderFieldCondition_ /*&cyclicBoundedField*/, "Electric Field"));
	feelField_.push_back(FeelField(/*&calculationModel_*/ &highSpeedModificationVerle_, &createField_.front(), &culonInterworking_, "Electric Feel", &dt_));

	for(int i = 0; i < 1000; i++) {
		electrons_.push_back(Particle(Vector((rand()/(double)RAND_MAX)*borders_.x_, (rand()/(double)RAND_MAX)*borders_.y_, (rand()/(double)RAND_MAX)*borders_.z_), Vector(.0, .0, .0), m_, z_, &elasticBorder_));
	}
	for_each(electrons_.begin(), electrons_.end(), [&](Particle& particle){
		createField_[0].addParticle(&particle);
		feelField_[0].addParticle(&particle);
	});
}
ElectronsInElasticCoub::~ElectronsInElasticCoub() {}

void ElectronsInElasticCoub::phyCoub() {
	for_each(feelField_.begin(), feelField_.end(), [](FeelField& feelField_) {
		feelField_.moveParticles();
	}
	);
}

} /* namespace phycoub */
