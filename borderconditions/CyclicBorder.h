/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 22:21:14
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 08:23:03
 */

#pragma once

#include <BorderCondition.h>

namespace phycoub
{

class CyclicBorder : public BorderCondition
{
  public:
    CyclicBorder( const Vector& borders );
    virtual ~CyclicBorder() = default;

    virtual void psyMove( const Vector& move, ParticlePtr* particle ) override;
};

using CyclicBorderPtr = std::shared_ptr< CyclicBorder >;

} // namespace phycoub
