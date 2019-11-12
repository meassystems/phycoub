/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 22:31:02
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-12 23:12:15
 */

#pragma once

#include <memory>

#include "FieldCreator.h"
#include "HomogeneousFieldIface.h"

namespace phycoub
{

class HomogeneousFieldCreator : public FieldCreator
{
  public:
    HomogeneousFieldCreator(
        HomogeneousFieldPtr homogeneousField, const std::string& fieldName );
    virtual ~HomogeneousFieldCreator() = default;

    virtual Vector getFieldInMark( const Vector& mark ) override;

  private:
    HomogeneousFieldPtr homogeneousField_;
};

using HomogeneousFieldCreatorPtr = std::shared_ptr< HomogeneousFieldCreator >;

} // namespace phycoub