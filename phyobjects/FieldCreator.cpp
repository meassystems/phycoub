/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-24 20:09:47
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 18:35:34
 */

#include "FieldCreator.h"

namespace phycoub
{

FieldCreator::FieldCreator( const std::string& fieldName )
    : fieldName_( fieldName_ )
{
}

void FieldCreator::setFieldName( const std::string& fieldName )
{
    fieldName_ = fieldName;
}

const std::string& FieldCreator::getFieldName() const
{
    return fieldName_;
}

} // namespace phycoub