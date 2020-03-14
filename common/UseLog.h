/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-14 10:08:23
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-14 14:28:22
 */

#pragma once

#include <Log.h>

namespace phycoub
{

class UseLog
{
  public:
    UseLog() = default;
    virtual ~UseLog() = default;

    virtual void setLog( LogPtr log );
    void releaseLog();

    template< typename Function >
    void writeLogMessageIfInitialized( Function function );

  protected:
    LogPtr getLog();

  private:
    LogPtr log_;
};

template< typename Function >
void UseLog::writeLogMessageIfInitialized( Function function )
{
    if ( log_ )
    {
        function( log_ );
    }
}

} // namespace phycoub