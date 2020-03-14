/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-14 09:05:10
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-14 14:28:54
 */

#pragma once

#include <memory>
#include <string>
#include <list>
#include <unordered_map>
#include <stdint.h>

#include "LogLevel.h"
#include "LogObserver.h"

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
    void writeMessage( const std::string& message, LogLevel level );

  private:
    std::list< LogObserverWeakPtr > observers_;

    static std::unordered_map< LogLevel, std::string > strLevel_;
};

} // namespace phycoub