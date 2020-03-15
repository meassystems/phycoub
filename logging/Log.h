/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-14 09:05:10
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 11:04:38
 */

#pragma once

#include <memory>
#include <string>
#include <list>
#include <unordered_map>
#include <stdint.h>

#include "LogLevel.h"
#include "LogObserver.h"
#include "ErrorCode.h"

namespace phycoub
{

class Log;
using LogPtr = std::shared_ptr< Log >;

class Log final
{
  public:
    Log() = default;
    ~Log() = default;

    void subsribeForUpdates( LogObserverWeakPtr observer );
    void writeMessage( ErrorCode errorCode, LogLevel level, ... );

  private:
    std::list< LogObserverWeakPtr > observers_;
};

} // namespace phycoub