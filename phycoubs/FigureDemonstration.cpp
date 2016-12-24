/*
 * FigureDemonstration.cpp
 *
 *  Created on: Dec 22, 2016
 *      Author: root
 */

#include <FigureDemonstration.h>

#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <time.h>

namespace phycoub {

FigureDemonstration::FigureDemonstration() {
	srand(time(NULL));
	rand(); rand(); rand();

	createField_.push_back(CreateField(&azotField_, &borderFieldCondition_, "LD NN Field"));
	feelField_.push_back(FeelField(/*&highSpeedModificationVerle_*/&leapFrog_, &createField_.back(), &azotInterworking, "LD NN Feel", &dt_));

//	createField_.push_back(CreateField(&azotField_, &borderFieldCondition_, "LD NN Field"));
//	feelField_.push_back(FeelField(&highSpeedModificationVerle_, &createField_.back(), &azotInterworking, "LD NN Feel", &dt_));


//	createField_.back().addGroupParticle(lineN.particles_);
//	feelField_.back().addGroupParticle(lineN.particles_);

	createField_.back().addGroupParticle(planeN.allParticles_);
	feelField_.back().addGroupParticle(planeN.centrallParticles_);
}
FigureDemonstration::~FigureDemonstration() {}

void FigureDemonstration::phyCoub() {
	for_each(feelField_.begin(), feelField_.end(), [](FeelField& feelField_) {
		feelField_.moveParticles();
	}
	);
}

} /* namespace phycoub */
