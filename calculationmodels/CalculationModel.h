/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 19:41:30
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 22:25:28
 */

#pragma once

#include "ParticleGroup.h"
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

    virtual void phyCalculate( ParticleGroupList* particleGroupList,
        BorderConditionPtr borderCondition, double dt );
};

} // namespace phycoub
