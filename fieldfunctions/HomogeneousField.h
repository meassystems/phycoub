/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 18:53:11
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 19:00:11
 */

#pragma once

#include "FieldIface.h"
#include "Vector.h"

namespace phycoub
{

class HomogeneousField : public FieldIface
{
  public:
    explicit HomogeneousField( const Vector& direction );
    virtual ~HomogeneousField() = default;

    void setDirection( const Vector& direction );
    const Vector& getDirection() const;

  private:
    Vector direction_;
};

using HomogeneousFieldPtr = std::shared_ptr< HomogeneousField >;

} // namespace phycoub