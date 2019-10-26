/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 22:40:46
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 18:39:45
 */

#include "HomogeneousFieldCreator.h"

namespace phycoub
{

HomogeneousFieldCreator::HomogeneousFieldCreator(
    HomogeneousFieldPtr homogeneousField, const std::string& fieldName )
    : FieldCreator( fieldName )
    , homogeneousField_( homogeneousField )
{
}

// virtual override
Vector HomogeneousFieldCreator::getFieldInMark( const Vector& mark )
{
    const Vector result = homogeneousField_->psyField( mark );
    return result;
}

} // namespace phycoub