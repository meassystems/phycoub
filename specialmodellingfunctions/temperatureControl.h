/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:18:00
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 00:55:41
 */

#pragma once

#include <vector>
#include <math.h>

#include "Vector.h"
#include "Particle.h"
#include "ParticleGroup.h"

namespace phycoub
{

void temperatureControl( double temp, double kB, ParticlePtr particle );
void temperatureControl( double temp, double kB, ParticleGroupPtr particleGroup );
void temperatureControl( double temp, double kB, ParticleGroupList particleGroupList );

} // namespace phycoub
