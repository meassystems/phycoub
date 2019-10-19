/*
 * BorderFieldCondition.h
 *
 *  Created on: 19 ���. 2016 �.
 *      Author: SFrancishkov
 */

#ifndef BORDERFIELDCONDITION_H_
#define BORDERFIELDCONDITION_H_

#include "Vector.h"

namespace phycoub
{

class CreateField;
/*
 * Базовый класс для задания граничных условий поля взаимодействия.
 * Чтобы создать свой метод необходим унаследоваться от данного класса и
 * переопределить метод phySumField.
 *
 * Базовая реализация содержит бесконечные граничные условия.
 */
class BorderFieldCondition
{
  public:
    BorderFieldCondition();
    virtual ~BorderFieldCondition();

    virtual Vector phySumField( CreateField *createField, const Vector &mark );
};

} /* namespace phycoub */

#endif /* BORDERFIELDCONDITION_H_ */
