/*
 * Particle.cpp
 *
 *  Created on: Oct 14, 2016
 *      Author: root
 */

#include "Particle.h"
#include "BorderCondition.h"

namespace phycoub {

Particle::Particle(): coordinate_(0., 0., 0.), speed_(0., 0., 0.), m_(0.), z_(0.),
		borderCondition_(new BorderCondition(new Vector()))
{
	++index;
	index_ = index;
}
Particle::Particle(const Vector& coordinate, const Vector& speed, const double& m, const double& z,
		BorderCondition* borderCondition) : coordinate_(coordinate), speed_(speed), m_(m), z_(z),
				borderCondition_(borderCondition)
{
	++index;
	index_ = index;
}
Particle::~Particle() {}

bool Particle::operator==(const Particle& particle) {
	return this->index == particle.index;
}

void Particle::move(const double& dt) {
	borderCondition_->psyMove(this->speed_ * dt, *this);
}
void Particle::move(const Vector& dr) {
	borderCondition_->psyMove(dr, *this);
}

long Particle::index(0);

} /* namespace phycoub */
