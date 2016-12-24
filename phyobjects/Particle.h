/*
 * Particle.h
 *
 *  Created on: Oct 14, 2016
 *      Author: root
 */


#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "Vector.h"

namespace phycoub {

class BorderCondition;
/*
 * Класс/объект моделируемого пространства - частица.
 */
class Particle {
public:
	Particle();
	Particle(const Vector& coordinate, const Vector& speed, const double& m, const double& z, BorderCondition* borderCondition);
	virtual ~Particle();

	bool operator==(const Particle& particle);

	void move(const double& dt);
	void move(const Vector& dr);

	static long index;
	long index_;
	Vector coordinate_, speed_;
	double m_, z_;
	BorderCondition* borderCondition_;

	Vector previesCordinate_{}, previesSpeed_{};
	Vector field_{}, interworking_{};
	double potentialEnergy = 0.;
};

} /* namespace phycoub */

#endif /* PARTICLE_H_ */
