/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-24 20:03:46
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-24 20:14:28
 */

#pragma once

#include <string>

#include "Vector.h"

namespace phycoub
{

class CreateFieldBase
{
  public:
    CreateFieldBase( const std::string& fieldName );
    virtual ~CreateFieldBase() = default;

    virtual Vector getFieldInMark( const Vector& mark ) = 0;

    void setFieldName( const std::string& fieldName );
    const std::string& getFieldName() const;

  private:
    std::string fieldName_;
};

} // namespace phycoub