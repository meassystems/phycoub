/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:11:55
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 13:42:28
 */

#pragma once

#include "BorderCondition.h"
#include "CubicShape.h"

namespace phycoub
{
/*
 * Упругие граничные условия в случае, если пространсво моделирования - прямоугольник.
 */
class ElasticCoubCondition
    : public BorderCondition
    , public CubicShape
{
  public:
    ElasticCoubCondition( const Vector& borders );
    virtual ~ElasticCoubCondition() = default;

    void psyMove(
        const Vector& move, const Vector& speed, ParticlePtr particle ) override;
};

using ElasticCoubConditionPtr = std::shared_ptr< ElasticCoubCondition >;

} // namespace phycoub
