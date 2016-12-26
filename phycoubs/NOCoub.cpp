/*
 * NOCoub.cpp
 *
 *  Created on: Dec 17, 2016
 *      Author: root
 */

#include <NOCoub.h>

#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "temperatureControl.h"

namespace phycoub {

NOCoub::NOCoub() {
	createField_.reserve(4);
	feelField_.reserve(4);
	srand(time(NULL));
	rand(); rand(); rand();
	// NN
	createField_.push_back(CreateField(&azotField_, &cyclicBoundedFieldN_, "LD NN Field"));
	feelField_.push_back(FeelField(&leapFrog, &createField_.back(), &azotInterworking, "LD NN Feel", &dt_));
	for(int i = 0; i < 100; i++) {
		azot_.push_back(Particle(Vector((rand()/(double)RAND_MAX)*borders_.x_, (rand()/(double)RAND_MAX)*borders_.y_,
				(rand()/(double)RAND_MAX)*borders_.z_), Vector(.0, .0, .0), mN_, z_, &cyclicBorder_));
	}
	createField_.back().addGroupParticle(azot_);
	feelField_.back().addGroupParticle(azot_);
	// OO
	createField_.push_back(CreateField(&oxygenField_, &cyclicBoundedFieldO_, "LD OO Field"));
	feelField_.push_back(FeelField(&leapFrog, &createField_.back(), &oxygenInterworking, "LD OO Feel", &dt_));
	for(int i = 0; i < 100; i++) {
		oxygen_.push_back(Particle(Vector((rand()/(double)RAND_MAX)*borders_.x_, (rand()/(double)RAND_MAX)*borders_.y_,
				(rand()/(double)RAND_MAX)*borders_.z_), Vector(.0, .0, .0), mO_, z_, &cyclicBorder_));
	}
	createField_.back().addGroupParticle(oxygen_);
	feelField_.back().addGroupParticle(oxygen_);
	// NO
	createField_.push_back(CreateField(&NOField_, &cyclicBoundedFieldNO_, "LD NO Field"));
	feelField_.push_back(FeelField(&leapFrog, &createField_.back(), &NOInterworking, "LD OO Feel", &dt_));
	createField_.back().addGroupParticle(azot_);
	feelField_.back().addGroupParticle(oxygen_);
	// ON
	createField_.push_back(CreateField(&NOField_, &cyclicBoundedFieldNO_, "LD NO Field"));
	feelField_.push_back(FeelField(&leapFrog, &createField_.back(), &NOInterworking, "LD OO Feel", &dt_));
	createField_.back().addGroupParticle(oxygen_);
	feelField_.back().addGroupParticle(azot_);
}
NOCoub::~NOCoub() {}

void NOCoub::phyCoub() {

	for_each(feelField_.begin(), feelField_.end(), [](FeelField& feelField_) {
		feelField_.moveParticles();
	}
	);
	temperatureControl(0., 2, k_, &azot_, &oxygen_);
}

} /* namespace phycoub */
