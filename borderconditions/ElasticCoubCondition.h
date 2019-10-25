/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:11:55
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 22:31:19
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
    ElasticCoubCondition( Vector* borders );
    virtual ~ElasticCoubCondition() = default;

    void psyMove( const Vector& move, ParticlePtr* particle ) override;
};

using ElasticCoubConditionPtr = std::shared_ptr< ElasticCoubCondition >;

} // namespace phycoub
