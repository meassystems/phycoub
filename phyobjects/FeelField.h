/*
 * FeelField.h
 *
 *  Created on: 17 ���. 2016 �.
 *      Author: SFrancishkov
 */

#ifndef FEELFIELD_H_
#define FEELFIELD_H_

#include <InterworkingFunction.h>
#include "CreateField.h"
#include "Vector.h"
#include "Particle.h"
#include <vector>
#include <string>

namespace phycoub {

class CalculationModel;
/*
 * Класс/объект моделируемого пространства - группа частиц реагирующих на поле.
 */
class FeelField {
public:
	FeelField(CreateField* createField, InterworkingFunction* interworkingFunction, std::string fieldName);
	virtual ~FeelField();


	virtual void phyCalcInterworking();

	void addParticle(Particle* particle);
	void addGroupParticle(std::vector<Particle*> &particles);
	void removeParticle(Particle* particle);

	CreateField* createField_;
	std::vector<Particle*> particles_;
	InterworkingFunction* interworkingFunction_;
	std::string fieldName_;
};

} /* namespace phycoub */

#endif /* FEELFIELD_H_ */
