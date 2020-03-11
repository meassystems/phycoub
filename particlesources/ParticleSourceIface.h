/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-01-05 01:33:26
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-12 00:39:29
 */

#pragma once

#include <memory>

#include "Particle.h"

namespace phycoub
{
/*
 * Интерфейс для источников частиц. Источники частиц рождают новые частицы
 */
class ParticleSourceIface
{

  public:
    virtual ~ParticleSourceIface() = default;

    virtual ParticlePtr phyGiveBirthParticle() = 0;
};

using ParticleSourcePtr = std::shared_ptr< ParticleSourceIface >;

} // namespace phycoub