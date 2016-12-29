/*
 * CreateField.h
 *
 *  Created on: 17 ���. 2016 �.
 *      Author: SFrancishkov
 */

#ifndef CREATEFIELD_H_
#define CREATEFIELD_H_

#include "Vector.h"
#include "Particle.h"
#include <vector>
#include "FieldFunction.h"
#include <string>

namespace phycoub {

class BorderFieldCondition;
/*
 * Класс/объект моделируемого пространства - группа частиц создающих поле.
 */
class CreateField {
public:
	CreateField(FieldFunction* functionField, BorderFieldCondition* borderFieldCondition, std::string fieldName);
	virtual ~CreateField();

	virtual Vector getFieldInMark(const Vector& mark);

	void addParticle(Particle* particle);
	void addGroupParticle(std::vector<Particle*> &particles);
	void removeParticle(Particle* particle);

	std::vector<Particle*> particles_;
	FieldFunction* functionField_;
	BorderFieldCondition* borderFieldCondition_;
	std::string fieldName_;
};

} /* namespace phycoub */

#endif /* CREATEFIELD_H_ */
