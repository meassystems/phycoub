/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-15 10:54:01
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 11:00:12
 */

#include "ErrorDescription.h"

#include "HasId.h"
#include "Utils.h"

namespace phycoub
{

std::unordered_map< ErrorCode, std::string ( * )( va_list ) >
    ErrorDescription::descriptionHandlers
    = { { ErrorCode::borderConditionsCoordinateGreaterChange,
        handleBorderConditionsCoordinateGreaterChange } };

std::string ErrorDescription::getErrorDescription( ErrorCode errorCode, va_list args )
{
    auto handle = descriptionHandlers.at( errorCode );
    return handle( args );
}

std::string ErrorDescription::handleBorderConditionsCoordinateGreaterChange(
    va_list args )
{
    IDType particleId = va_arg( args, IDType );
    return Utils::formatString(
        "Particle[%lu] changes its coordinate by an amount "
        "greater than the 5%% size of the cube. Try to reduce 'dt'",
        particleId );
}

} // namespace phycoub