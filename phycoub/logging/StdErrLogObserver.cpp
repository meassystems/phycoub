/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-14 11:25:56
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 11:05:07
 */

#include "StdErrLogObserver.h"

#include <iostream>

#include "Utils.h"
#include "ErrorDescription.h"

namespace phycoub
{

// static
std::unordered_map< LogLevel, std::string > StdErrLogObserver::strLevel_
    = { { LogLevel::info, "info" }, { LogLevel::warning, "warning" },
          { LogLevel::error, "error" } };

// virtual override
void StdErrLogObserver::onLogMessage(
    ErrorCode errorCode, LogLevel level, std::time_t time, va_list args )
{
    const std::string errorDescription
        = ErrorDescription::getErrorDescription( errorCode, args );

    std::cerr << formatMessage( errorDescription, strLevel_.at( level ), time )
              << std::endl;
}

// static
std::string StdErrLogObserver::getDateTimeString( std::time_t time )
{
    std::string date;
    date.resize( 100 );

    size_t length = std::strftime( const_cast< char* >( date.data() ), date.size(),
        "{%T %F}", std::localtime( &time ) );
    date.resize( length );

    return date;
}

// static
std::string StdErrLogObserver::formatMessage(
    const std::string& message, const std::string& level, std::time_t time )
{
    std::string date = getDateTimeString( time );
    std::string logMessage
        = Utils::formatString( "%s[%s] %s", date.data(), level.data(), message.data() );

    return logMessage;
}

} // namespace phycoub