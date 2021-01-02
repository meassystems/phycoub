/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-15 10:48:03
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 10:53:26
 */

#pragma once

#include <string>
#include <unordered_map>
#include <stdarg.h>

#include "ErrorCode.h"

namespace phycoub
{

class ErrorDescription final
{
  public:
    ErrorDescription() = delete;

    static std::string getErrorDescription( ErrorCode errorCode, va_list args );

  private:
    static std::string handleBorderConditionsCoordinateGreaterChange( va_list args );

    static std::unordered_map< ErrorCode, std::string ( * )( va_list ) >
        descriptionHandlers;
};

} // namespace phycoub