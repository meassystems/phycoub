/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-24 19:47:12
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-12 00:26:09
 */

#pragma once

#include <memory>

#include <BorderFieldCondition.h>
#include "Vector.h"

namespace phycoub
{
/*
 * Циклические граничные условия
 */
/*
 *   Старый код, переделать на более простую схему
 */
class CyclicBoundedField : public BorderFieldCondition
{
  public:
    CyclicBoundedField( const Vector& borders, double radiusCut );
    virtual ~CyclicBoundedField() = default;

    virtual Vector phyFieldWithBorderCondition(
        FieldPtr field, const ParticlePtr particle, const Vector& mark ) override;

    void setBorders( const Vector& borders );
    const Vector& getBorders() const;

    void setRadiusCut( double radiusCut );
    double getRadiusCut() const;

  private:
    /* Функция добавления грани переноса поля */
    void addTransfer( int num );

    double radiusCut_;
    Vector borders_;

    Vector transferConst[ 27 ];
    bool intersection[ 6 ] = { false };
    int transferNum[ 27 ] = { 0 };
    int transferQuantity = 0;
};

using CyclicBoundedFieldPtr = std::shared_ptr< CyclicBoundedField >;

} // namespace phycoub
