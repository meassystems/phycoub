/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:07:20
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-12 00:25:57
 */

#pragma once

#include "BorderCondition.h"
#include "CubicShape.h"
#include "Vector.h"

namespace phycoub
{
/*
 * Упругие граничные условия.
 */
/*
 *   Старый код, переделать на более простую схему
 */
class ElasticBorder
    : public BorderCondition
    , public CubicShape
{
  public:
    void psyMove(
        const Vector& move, const Vector& speed, ParticlePtr* particle ) override;

  private:
    // todo correct speed vector
    ElasticBorder( const Vector& borders );
    virtual ~ElasticBorder() = default;

    struct PlaneMarket
    {
        Vector M1;
        Vector M2;
        Vector M3;
    };
    struct IntersectionVector
    {
        Vector intersectionMark;
        bool intersection;
        int planeIntersection;
    };

    /* Получить новый вектор отражения */
    const IntersectionVector getIntersectionVector(
        const Vector& move, const Vector& coordinate );
    /* Функция для получения точки пересечения траектории с границей моделирования */
    const Vector getMarkIntersection(
        const PlaneMarket& planeMarket, const Vector& mark, const Vector& direction );
    /* Функция для проверки нахождения частицы в границах TODO */
    bool isMarkInBorder( const Vector& mark );
};

using ElasticBorderPtr = std::shared_ptr< ElasticBorder >;

} // namespace phycoub
