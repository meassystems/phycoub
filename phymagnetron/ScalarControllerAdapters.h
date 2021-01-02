#ifndef SCALARCONTROLLERADAPTERS_H
#define SCALARCONTROLLERADAPTERS_H

#include <memory>

#include "ValueControllerAdapterIface.h"
#include "Magnetron.h"

namespace phymagnetron
{

using namespace phycoub;
using namespace phywidgets;

using RadiusScalarControllerAdapter = ValueControllerAdapter< double, Magnetron,
    &Magnetron::getRadius, &Magnetron::setRadius >;
using RadiusScalarControllerAdapterPtr = std::shared_ptr< RadiusScalarControllerAdapter >;

using HeightScalarControllerAdapter = ValueControllerAdapter< double, Magnetron,
    &Magnetron::getHeight, &Magnetron::setHeigtht >;
using HeightScalarControllerAdapterPtr = std::shared_ptr< HeightScalarControllerAdapter >;

using MagneticScalarControllerAdapter = ValueControllerAdapter< double, Magnetron,
    &Magnetron::getMagneticFieldInduction, &Magnetron::setMagneticFieldInduction >;
using MagneticScalarControllerAdapterPtr
    = std::shared_ptr< MagneticScalarControllerAdapter >;

using ElectricScalarControllerAdapter = ValueControllerAdapter< double, Magnetron,
    &Magnetron::getElectricRadialFieldCharge, &Magnetron::setElectricRadialFieldCharge >;
using ElectricScalarControllerAdapterPtr
    = std::shared_ptr< ElectricScalarControllerAdapter >;

using EnergyScalarControllerAdapter = ValueControllerAdapter< double, Magnetron,
    &Magnetron::getEnergy, &Magnetron::setEnergy >;
using EnergyScalarControllerAdapterPtr = std::shared_ptr< EnergyScalarControllerAdapter >;

using LifeParticleCountScalarControllerAdapter = ValueControllerAdapter< long, Magnetron,
    &Magnetron::getLifeParticleCount, &Magnetron::setLifeParticleCount >;
using LifeParticleCountScalarControllerAdapterPtr
    = std::shared_ptr< LifeParticleCountScalarControllerAdapter >;

} // namespace phymagnetron

#endif // SCALARCONTROLLERADAPTERS_H
