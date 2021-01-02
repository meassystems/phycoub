/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-24 20:09:47
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 11:07:40
 */

#include "FieldCreator.h"

namespace phycoub
{

FieldCreator::FieldCreator( const std::string& fieldName )
    : fieldName_( fieldName )
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