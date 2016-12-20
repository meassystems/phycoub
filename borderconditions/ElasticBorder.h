/*
 * ElasticBorder.h
 *
 *  Created on: Oct 16, 2016
 *      Author: root
 */

#ifndef ELASTICBORDER_H_
#define ELASTICBORDER_H_

#include <BorderCondition.h>
#include "Vector.h"

namespace phycoub {
/*
 * Упругие граничные условия.
 */
class ElasticBorder: public BorderCondition {
public:
	ElasticBorder(Vector* borders);
	virtual ~ElasticBorder();

	void psyMove(const Vector& move, Particle& particle);
private:
	struct PlaneMarket{
		Vector M1;
		Vector M2;
		Vector M3;
	};
	struct IntersectionVector{
		Vector intersectionMark;
		bool intersection;
		int planeIntersection;
	};

	/* Получить новый вектор отражения */
	const IntersectionVector getIntersectionVector(const Vector& move, const Particle& particle);
	/* Функция для получения точки пересечения траектории с границей моделирования */
	const Vector getMarkIntersection(const PlaneMarket& planeMarket, const Vector& mark, const Vector& direction);
	/* Функция для проверки нахождения частицы в границах TODO */
	bool isMarkInBorder(const Vector& mark);
};

} /* namespace phycoub */

#endif /* ELASTICBORDER_H_ */
