/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-15 22:26:19
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 22:37:04
 */

#pragma once

#include "Vector.h"

namespace phycoub
{

class RandomUtils final
{
  public:
    RandomUtils() = delete;

    static double generateNormalizedDouble();
    static double getRandomSign();
    static Vector generateXYDirection();
    static Vector generateRandomNormalizedVector();
};

} // namespace phycoub