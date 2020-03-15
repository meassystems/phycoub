/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-14 11:22:36
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 11:06:52
 */

#pragma once

#include <memory>
#include <unordered_map>

#include "LogObserver.h"

namespace phycoub
{

class StdErrLogObserver final : public LogObserver
{
  public:
    StdErrLogObserver() = default;
    virtual ~StdErrLogObserver() override = default;

    virtual void onLogMessage(
        ErrorCode errorCode, LogLevel level, std::time_t time, va_list args ) override;

  private:
    static std::string getDateTimeString( std::time_t time );
    static std::string formatMessage(
        const std::string& message, const std::string& level, std::time_t time );

    static std::unordered_map< LogLevel, std::string > strLevel_;
};

using StdErrLogObserverPtr = std::shared_ptr< StdErrLogObserver >;

} // namespace phycoub