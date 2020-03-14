/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-14 11:25:56
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-14 15:55:35
 */

#include "StdErrLogObserver.h"

#include <iostream>

#include "Utils.h"

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
    std::string date = getDateTimeString( time );
    std::string logMessage
        = Utils::formatString( "%s[%s] %s", date.data(), level.data(), message.data() );

    return logMessage;
}

} // namespace phycoub