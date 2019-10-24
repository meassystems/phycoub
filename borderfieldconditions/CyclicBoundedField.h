/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-24 19:47:12
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-24 20:41:04
 */

#pragma once

#include <BorderFieldCondition.h>
#include "Vector.h"

namespace phycoub
{
/*
 * Циклические граничные условия
 */
class CyclicBoundedField : public BorderFieldCondition
{
  public:
    CyclicBoundedField( double* radiusCut, Vector* borders );
    virtual ~CyclicBoundedField();

    virtual Vector phyFieldWithBorderCondition( FieldFunction* fieldFunction,
        const Particle& particle, const Vector& mark ) override;

    double* radiusCut_;
    Vector* borders_;

  private:
    /* Функция добавления грани переноса поля */
    void addTransfer( int num );

    Vector transferConst[ 27 ];
    bool intersection[ 6 ] = { false };
    int transferNum[ 27 ] = { 0 };
    int transferQuantity = 0;
};

} // namespace phycoub
