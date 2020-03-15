/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-16 01:00:02
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-16 01:03:29
 */

#include "ParticleOptionsCatalog.h"

#include "Constants.h"

namespace phycoub
{

const ParticleOptions& ParticleOptionsCatalog::getElectronOptions()
{
    static const ParticleOptions electronOptions{ ElectricConstants::electronWeight,
        ElectricConstants::electronCharge };

    return electronOptions;
}

} // namespace phycoub