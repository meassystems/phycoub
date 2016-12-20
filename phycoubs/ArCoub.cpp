/*
 * ArCoub.cpp
 *
 *  Created on: 20 дек. 2016 г.
 *      Author: serv
 */

#include <ArCoub.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <time.h>

namespace phycoub {
ArCoub::ArCoub() {
	createField_.push_back(CreateField(&argonField_, &borderFieldCondition_, "LD Argon Field"));
	feelField_.push_back(FeelField(&highSpeedModificationVerle_, &createField_.back(), &argontInterworking, "LD Argon Feel", &dt_));
	argon_.push_back(Particle(Vector(0.3,0.3,0.3)*borders_.x_, Vector(.0,.0,.0), mAr_, z_, &elasticBorder_));
	argon_.push_back(Particle(Vector(0.3,0.3,0.5)*borders_.x_, Vector(.0,.0,.0), mAr_, z_, &elasticBorder_));
	createField_.back().addGroupParticle(argon_);
	feelField_.back().addGroupParticle(argon_);
}

ArCoub::~ArCoub() {}

void ArCoub::phyCoub() {
	for_each(feelField_.begin(), feelField_.end(), [](FeelField& feelField_) {
		feelField_.moveParticles();
	}
	);
}

} /* namespace phycoub */
