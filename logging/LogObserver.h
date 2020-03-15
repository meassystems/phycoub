/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-14 09:11:29
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 10:45:38
 */

#pragma once

#include <string>
#include <memory>
#include <ctime>

#include "LogLevel.h"
#include "ErrorCode.h"

namespace phycoub
{

class LogObserver
{
  public:
    virtual ~LogObserver() = default;

    virtual void onLogMessage(
        ErrorCode errorCode, LogLevel level, std::time_t time, va_list args )
        = 0;
};

using LogObserverPtr = std::shared_ptr< LogObserver >;
using LogObserverWeakPtr = std::weak_ptr< LogObserver >;

} // namespace phycoub