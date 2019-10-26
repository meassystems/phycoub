/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 22:40:46
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 12:30:51
 */

#include "CreateHomogeneousField.h"

namespace phycoub
{

CreateHomogeneousField::CreateHomogeneousField(
    HomogeneousFieldPtr homogeneousField, const std::string& fieldName )
    : CreateFieldBase( fieldName )
    , homogeneousField_( homogeneousField )
{
}

// virtual override
Vector CreateHomogeneousField::getFieldInMark( const Vector& mark )
{
    const Vector result = homogeneousField_->psyField( mark );
    return result;
}

} // namespace phycoub