/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-14 10:17:29
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-14 14:29:26
 */

#include "Log.h"

#include "Utils.h"

namespace phycoub
{

// static
std::unordered_map< LogLevel, std::string > Log::strLevel_ = { { LogLevel::info, "info" },
    { LogLevel::warning, "warning" }, { LogLevel::error, "error" } };

void Log::subsribeForUpdates( LogObserverWeakPtr observer )
{
    observers_.push_back( observer );
}

void Log::writeMessage( const std::string& message, LogLevel level )
{
    Utils::callForObserversAndRemoveReleasedPtrs(
        &observers_, [&message, level]( LogObserverPtr observer ) {
            observer->onLogMessage(
                message, strLevel_.at( level ), std::time( nullptr ) );
        } );
}

} // namespace phycoub