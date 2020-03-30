/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-14 10:17:29
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 11:04:59
 */

#include "Log.h"

#include <stdarg.h>

#include "Utils.h"

namespace phycoub
{

void Log::subsribeForUpdates( LogObserverWeakPtr observer )
{
    observers_.push_back( observer );
}

void Log::writeMessage( ErrorCode errorCode, LogLevel level, ... )
{
    va_list args;
    va_start( args, level );

    Utils::callForObserversAndRemoveReleasedPtrs(
        &observers_, [errorCode, level, &args]( LogObserverPtr observer ) {
            observer->onLogMessage( errorCode, level, std::time( nullptr ), args );
        } );

    va_end( args );
}

} // namespace phycoub