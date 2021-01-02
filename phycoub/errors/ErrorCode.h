/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-15 09:46:08
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 09:48:41
 */

#pragma once

#include <stdint.h>

namespace phycoub
{

enum class ErrorCode : uint64_t
{
    borderConditionsCoordinateGreaterChange = 100,
};

}