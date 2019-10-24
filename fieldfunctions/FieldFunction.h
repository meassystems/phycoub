/*
 * FieldFunction.h
 *
 *  Created on: 17 ���. 2016 �.
 *      Author: SFrancishkov
 */

#ifndef FIELDFUNCTION_H_
#define FIELDFUNCTION_H_

#include "Vector.h"
#include "Particle.h"

namespace phycoub
{
/*
 * Абстрактный класс для реализации функции поля. Чтобы создать свою функцию поля
 * необходимо унаследоваться отданного класса и определить метод psyField.
 */
class FieldFunction
{
  public:
    virtual ~FieldFunction();

    virtual Vector psyField( const Particle& source, const Vector& mark ) = 0;
};

} /* namespace phycoub */

#endif /* FIELDFUNCTION_H_ */
