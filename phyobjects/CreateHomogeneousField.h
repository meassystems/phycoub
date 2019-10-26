/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 22:31:02
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 15:22:12
 */

#pragma once

#include <memory>

#include "CreateFieldBase.h"
#include "HomogeneousField.h"

namespace phycoub
{

class CreateHomogeneousField : public CreateFieldBase
{
  public:
    CreateHomogeneousField(
        HomogeneousFieldPtr homogeneousField, const std::string& fieldName );
    virtual ~CreateHomogeneousField() = default;

    virtual Vector getFieldInMark( const Vector& mark ) override;

  private:
    HomogeneousFieldPtr homogeneousField_;
};

using CreateHomogeneousFieldPtr = std::shared_ptr< CreateHomogeneousField >;

} // namespace phycoub