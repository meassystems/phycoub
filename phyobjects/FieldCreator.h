/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-24 20:03:46
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-28 16:42:41
 */

#pragma once

#include <string>
#include <memory>

#include "Vector.h"

namespace phycoub
{

class FieldCreator
{
  public:
    FieldCreator( const std::string& fieldName );
    virtual ~FieldCreator() = default;

    virtual Vector getFieldInMark( const Vector& mark ) = 0;

    void setFieldName( const std::string& fieldName );
    const std::string& getFieldName() const;

  private:
    std::string fieldName_;
};

using FieldCreatorPtr = std::shared_ptr< FieldCreator >;

} // namespace phycoub