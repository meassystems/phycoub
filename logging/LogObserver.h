/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-14 09:11:29
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-14 13:46:41
 */

#pragma once

#include <string>
#include <memory>
#include <ctime>

#include "LogLevel.h"

namespace phycoub
{

class LogObserver
{
  public:
    virtual ~LogObserver() = default;

    virtual void onLogMessage(
        const std::string& message, const std::string& level, std::time_t time )
        = 0;
};

using LogObserverPtr = std::shared_ptr< LogObserver >;
using LogObserverWeakPtr = std::weak_ptr< LogObserver >;

} // namespace phycoub