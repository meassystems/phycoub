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
	feelField_.push_back(FeelField(&leapFrog, &createField_.back(), &argontInterworking, "LD Argon Feel", &dt_));
	for(int i = 0; i < 842; ++i) {
	argon_.push_back(Particle(Vector((rand()/(double)RAND_MAX)*borders_.x_, (rand()/(double)RAND_MAX)*borders_.y_,
			(rand()/(double)RAND_MAX)*borders_.z_), Vector(.0,.0,.0), mAr_, z_, &thermostatBorder));
	}
	createField_.back().addGroupParticle(argon_);
	feelField_.back().addGroupParticle(argon_);
}

ArCoub::~ArCoub() {}

void ArCoub::phyCoub() {
	timeExperimet += dt_;
	for_each(feelField_.begin(), feelField_.end(), [](FeelField& feelField_) {
		feelField_.moveParticles();
	}
	);
}

} /* namespace phycoub */
