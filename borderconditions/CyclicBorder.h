/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 22:21:14
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 13:41:26
 */

#pragma once

#include "BorderCondition.h"
#include "CubicShape.h"

namespace phycoub
{
/*
 *   Цикличные граничные условия(перенос с противоположной стороны)
 */
class CyclicBorder
    : public BorderCondition
    , public CubicShape
{
  public:
    CyclicBorder( const Vector& borders );
    virtual ~CyclicBorder() = default;

    virtual void psyMove(
        const Vector& move, const Vector& speed, ParticlePtr particle ) override;

  private:
    double minBorderSize = 0.;
};

using CyclicBorderPtr = std::shared_ptr< CyclicBorder >;

} // namespace phycoub
