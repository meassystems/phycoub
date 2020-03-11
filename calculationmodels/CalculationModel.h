/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 19:41:30
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 17:56:00
 */

#pragma once

#include <memory>

#include "ParticleGroupList.h"
#include "BorderCondition.h"

namespace phycoub
{

class CalculationGroup;
/*
 * Базовый класс для реализации методики расчета.
 * Для реализации собственного метода расчета необходимо унаследоваться от данного класса
 * и переопределить метод phyCalculate.
 *
 * Базовая реализация содержит метод расчета реализующий расчет изменения скорости
 * умножением ранводействующей силы на шаг по времени и деленой на массу частицы.
 */
class CalculationModel
{
  public:
    CalculationModel() = default;
    virtual ~CalculationModel() = default;

    virtual void phyCalculate( BorderConditionPtr borderCondition, double dt,
        const ParticleGroupList& particleGroupList );
};

using CalculationModelPtr = std::shared_ptr< CalculationModel >;

} // namespace phycoub
