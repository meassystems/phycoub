/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-03 14:27:52
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-01-03 14:33:48
 */

#include "BorderReachedEventGenerator.h"

namespace phycoub
{

void BorderReachedEventGenerator::borderReached( ParticlePtr particle )
{
    for ( auto observerWeak : observers )
    {
        if ( auto observer = observerWeak.lock() )
        {
            observer->onBorderReached( particle );
        }
    }
};

void BorderReachedEventGenerator::addBorderReachedObserver(
    BorderReachedObserverPtr observer )
{
    observers.push_back( observer );
};

} // namespace phycoub