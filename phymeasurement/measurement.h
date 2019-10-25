/*
 * measurement.h
 *
 *  Created on: Dec 26, 2016
 *      Author: root
 */

#ifndef MEASUREMENT_H_
#define MEASUREMENT_H_

#include <vector>

#include "ParticleGroup.h"

namespace phycoub
{

double getTemperature( double kB, ParticleGroupPtr particles );
double getTemperatureWithoutEnergyTranslationalMotionSystem(
    double kB, ParticleGroupPtr particles );

double getWk( ParticleGroupPtr particles );
double getWkWithoutTranslationalMotion( ParticleGroupPtr particles );

} // namespace phycoub

#endif /* MEASUREMENT_H_ */
