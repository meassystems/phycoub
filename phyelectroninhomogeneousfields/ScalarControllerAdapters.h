#ifndef SCALARCONTROLLERADAPTERS_H
#define SCALARCONTROLLERADAPTERS_H

#include <memory>

#include "ValueControllerAdapterIface.h"
#include "ElectronInHomogeneousFieldsCoub.h"

namespace phyelectroninhomogeneousfields
{

using namespace phycoub;
using namespace phywidgets;

using SizeScalarControllerAdapter = ValueControllerAdapter< Vector,
    ElectronInHomogeneousFieldsCoub, &ElectronInHomogeneousFieldsCoub::getBorders,
    &ElectronInHomogeneousFieldsCoub::setBorders >;
using SizeScalarControllerAdapterPtr = std::shared_ptr< SizeScalarControllerAdapter >;

using E2EScalarControllerAdapter
    = ValueControllerAdapter< bool, ElectronInHomogeneousFieldsCoub,
        &ElectronInHomogeneousFieldsCoub::getElectron2ElectronInterworkingFlag,
        &ElectronInHomogeneousFieldsCoub::setElectron2ElectronInterworkingFlag >;
using E2EScalarControllerAdapterPtr = std::shared_ptr< E2EScalarControllerAdapter >;

using MagneticDirectionScalarControllerAdapter
    = ValueControllerAdapter< Vector, ElectronInHomogeneousFieldsCoub,
        &ElectronInHomogeneousFieldsCoub::getMagneticFieldDirection,
        &ElectronInHomogeneousFieldsCoub::setMagneticFieldDirection >;
using MagneticDirectionScalarControllerAdapterPtr
    = std::shared_ptr< MagneticDirectionScalarControllerAdapter >;

using MagneticScalarControllerAdapter
    = ValueControllerAdapter< double, ElectronInHomogeneousFieldsCoub,
        &ElectronInHomogeneousFieldsCoub::getMagneticFieldInduction,
        &ElectronInHomogeneousFieldsCoub::setMagneticFieldInduction >;
using MagneticScalarControllerAdapterPtr
    = std::shared_ptr< MagneticScalarControllerAdapter >;

using ElectricDirectionScalarControllerAdapter
    = ValueControllerAdapter< Vector, ElectronInHomogeneousFieldsCoub,
        &ElectronInHomogeneousFieldsCoub::getElectricFieldDirection,
        &ElectronInHomogeneousFieldsCoub::setElectricFieldDirection >;
using ElectricDirectionScalarControllerAdapterPtr
    = std::shared_ptr< ElectricDirectionScalarControllerAdapter >;

using ElectricScalarControllerAdapter
    = ValueControllerAdapter< double, ElectronInHomogeneousFieldsCoub,
        &ElectronInHomogeneousFieldsCoub::getElectricFieldCharge,
        &ElectronInHomogeneousFieldsCoub::setElectricFieldCharge >;
using ElectricScalarControllerAdapterPtr
    = std::shared_ptr< ElectricScalarControllerAdapter >;

} // namespace phyelectroninhomogeneousfields

#endif // SCALARCONTROLLERADAPTERS_H
