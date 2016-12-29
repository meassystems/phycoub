/*
 * InterworkingFunction.h
 *
 *  Created on: Oct 14, 2016
 *      Author: root
 */

#ifndef INTERWORKINGFUNCTION_H_
#define INTERWORKINGFUNCTION_H_

#include "Vector.h"
#include "Particle.h"

namespace phycoub {
/*
 * Абстрактный класс для реализации функции расчета силы.
 * Для создания собственной функции расчета силы необходимо унаследоваться от данного класса и определить
 * функцию psyForce.
 */
class InterworkingFunction {
public:
	virtual ~InterworkingFunction();

	const virtual Vector psyForce(const Vector &field, const Particle* particle) = 0;
};

} /* namespace phycoub */

#endif /* INTERWORKINGFUNCTION_H_ */
