/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:11:55
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 08:33:05
 */

#pragma once

#include <BorderCondition.h>

namespace phycoub
{
/*
 * Упругие граничные условия в случае, если пространсво моделирования - прямоугольник.
 */
class ElasticCoubCondition : public BorderCondition
{
  public:
    ElasticCoubCondition( const Vector& borders );
    virtual ~ElasticCoubCondition() = default;

    void psyMove(
        const Vector& move, const Vector& newSpeed, ParticlePtr* particle ) override;
};

using ElasticCoubConditionPtr = std::shared_ptr< ElasticCoubCondition >;

} // namespace phycoub
