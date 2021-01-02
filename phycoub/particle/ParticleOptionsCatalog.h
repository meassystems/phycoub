/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-16 00:53:00
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-16 01:02:22
 */

#pragma once

#include "ParticleOptions.h"

namespace phycoub
{

class ParticleOptionsCatalog final
{
  public:
    ParticleOptionsCatalog() = delete;

    static const ParticleOptions& getElectronOptions();
};

} // namespace phycoub