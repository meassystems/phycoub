/*
 * CyclicBoundedField.h
 *
 *  Created on: 19 ���. 2016 �.
 *      Author: SFrancishkov
 */

#ifndef CYCLICBOUNDEDFIELD_H_
#define CYCLICBOUNDEDFIELD_H_

#include <BorderFieldCondition.h>
#include "Vector.h"

namespace phycoub {
/*
 * Циклические граничные условия
 */
class CyclicBoundedField: public BorderFieldCondition {
public:
	CyclicBoundedField(double* radiusCut, Vector* borders);
	virtual ~CyclicBoundedField();

	virtual Vector phySumField(CreateField* createField, const Vector& mark) override;

	double* radiusCut_;
	Vector* borders_;

private:
	/* Функция добавления грани переноса поля */
	void addTransfer(int num);

	Vector transferConst[27];
	bool intersection[6] = {false};
	int transferNum[27] = {0};
	int transferQuantity = 0;
};

} /* namespace phycoub */

#endif /* CYCLICBOUNDEDFIELD_H_ */
