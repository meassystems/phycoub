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

#include "temperatureControl.h"

namespace phycoub
{

ArCoub::ArCoub()
{
	createField_.push_back(CreateField(&argonField_, &borderFieldCondition_, "LD Argon Field"));
	feelField_.push_back(FeelField(&createField_.back(), &argontInterworking, "LD Argon Feel"));
	groupLeapFrog_.push_back(CalculationGroup(&leapFrog, &dt_));

	for (int i = 0; i < 400; ++i)
	{
		argon_.push_back(new Particle(Vector((rand() / (double)RAND_MAX) * borders_.x_,
											 (rand() / (double)RAND_MAX) * borders_.y_ * 0.7 + 0.3 * borders_.z_,
											 (rand() / (double)RAND_MAX) * borders_.z_),
									  Vector(.0, .0, .0), mAr_, z_, &thermostatBorder));
	}

	createField_.back().addGroupParticle(argon_);
	feelField_.back().addGroupParticle(argon_);
	groupLeapFrog_.back().addGroupParticle(argon_);

	createField_.back().addGroupParticle(parallelepipedFigure.allParticles_);
	feelField_.back().addGroupParticle(parallelepipedFigure.allParticles_);
	//groupLeapFrog_.back().addGroupParticle(parallelepipedFigure.allParticles_);
}

ArCoub::~ArCoub()
{
	for (Particle *particle : argon_)
	{
		delete particle;
	}
	argon_.clear();
}

void ArCoub::phyCoub()
{
	timeExperimet += dt_;

	for_each(feelField_.begin(), feelField_.end(), [](FeelField &feelField_) {
		feelField_.phyCalcInterworking();
	});
	for_each(groupLeapFrog_.begin(), groupLeapFrog_.end(), [](CalculationGroup &groupLeapFrog_) {
		groupLeapFrog_.phyModeling();
	});
}

} /* namespace phycoub */
