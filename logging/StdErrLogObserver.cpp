/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-14 11:25:56
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-14 13:48:32
 */

#include "StdErrLogObserver.h"

#include <iostream>

namespace phycoub
{

// virtual override
void StdErrLogObserver::onLogMessage(
    const std::string& message, const std::string& level, std::time_t time )
{
    std::cerr << formatMessage( message, level, time ) << std::endl;
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
    constexpr const char* strLevelSeparator = ": ";

    std::string date = getDateTimeString( time );

    // todo std::format in C++20
    std::string logMessage;
    logMessage.resize( 500 );
    size_t length = snprintf( const_cast< char* >( logMessage.data() ),
        logMessage.length(), "%s[%s] %s", date.data(), level.data(), message.data() );
    logMessage.resize( length );

    return logMessage;
}

} // namespace phycoub