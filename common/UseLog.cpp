/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-14 10:12:51
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-14 10:15:21
 */

#include "UseLog.h"

namespace phycoub
{

void UseLog::setLog( LogPtr theLog )
{
    log = theLog;
}

void UseLog::releaseLog()
{
    log.reset();
}

LogPtr UseLog::getLog()
{
    return log;
}

} // namespace phycoub