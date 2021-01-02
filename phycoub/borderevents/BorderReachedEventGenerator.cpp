/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-03 14:27:52
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-14 10:41:26
 */

#include "BorderReachedEventGenerator.h"
#include "Utils.h"

namespace phycoub
{

void BorderReachedEventGenerator::borderReached( ParticlePtr particle )
{
    Utils::callForObserversAndRemoveReleasedPtrs(
        &observers, [particle]( BorderReachedObserverPtr observer ) {
            observer->onBorderReached( particle );
        } );
};

void BorderReachedEventGenerator::addBorderReachedObserver(
    BorderReachedObserverWeakPtr observer )
{
    observers.push_back( observer );
};

} // namespace phycoub