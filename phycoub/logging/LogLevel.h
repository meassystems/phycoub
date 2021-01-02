/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-14 09:12:56
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-14 13:56:27
 */

#pragma once

#include <stdint.h>

namespace phycoub
{

enum class LogLevel : uint8_t
{
    info = 0,
    warning,
    error,

    count
};

}