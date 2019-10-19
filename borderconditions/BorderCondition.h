/*
 * BorderCondition.h
 *
 *  Created on: Oct 14, 2016
 *      Author: root
 */

#ifndef BORDERCONDITION_H_
#define BORDERCONDITION_H_

#include "Vector.h"

namespace phycoub
{

class Particle;
/*
 * Базовый класс для методов реализации граничных условий.
 * Для создания новых граничных условий необходимо унаследоваться от
 * данного класса и переопределить функцию psyMove.
 *
 * Базовая реализация содержит безконечные граничные условия.
 */
class BorderCondition
{
  public:
    BorderCondition( Vector *borders );
    virtual ~BorderCondition();

    virtual void psyMove( const Vector &move, Particle &particle );

    Vector *borders_;
};

} /* namespace phycoub */

#endif /* BORDERCONDITION_H_ */
