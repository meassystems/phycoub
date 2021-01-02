/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-14 10:12:51
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-14 14:28:39
 */

#include "UseLog.h"

namespace phycoub
{

void UseLog::setLog( LogPtr log )
{
    log_ = log;
}

void UseLog::releaseLog()
{
    log_.reset();
}

LogPtr UseLog::getLog()
{
    return log_;
}

} // namespace phycoub