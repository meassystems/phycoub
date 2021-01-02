/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-15 22:29:11
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 22:31:41
 */

#include "RandomUtils.h"

#include <random>
#include <math.h>

namespace phycoub
{

double RandomUtils::generateNormalizedDouble()
{
    static std::random_device device;
    static std::mt19937 generator( device() );
    static std::uniform_real_distribution< double > distribution( 0., 1. );

    return distribution( generator );
}

double RandomUtils::getRandomSign()
{
    if ( generateNormalizedDouble() >= 0.5 )
    {
        return 1.;
    }

    return -1.;
}

Vector RandomUtils::generateXYDirection()
{
    const double x = generateNormalizedDouble() * getRandomSign();
    const double y = sqrt( 1 - pow( x, 2 ) ) * getRandomSign();
    return Vector{ x, y, 0 };
}

} // namespace phycoub