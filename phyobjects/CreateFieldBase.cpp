/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-24 20:09:47
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-24 20:45:50
 */

#include "CreateFieldBase.h"

namespace phycoub
{

CreateFieldBase::CreateFieldBase( const std::string& fieldName )
    : fieldName_( fieldName_ )
{
}

void CreateFieldBase::setFieldName( const std::string& fieldName )
{
    fieldName_ = fieldName;
}

const std::string& CreateFieldBase::getFieldName() const
{
    return fieldName_;
}

} // namespace phycoub