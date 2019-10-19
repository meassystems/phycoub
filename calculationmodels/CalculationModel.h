/*
 * CalculationModel.h
 *
 *  Created on: 19 ���. 2016 �.
 *      Author: SFrancishkov
 */

#ifndef CALCULATIONMODEL_H_
#define CALCULATIONMODEL_H_

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
    CalculationModel();
    virtual ~CalculationModel();

    virtual void phyCalculate( CalculationGroup *calculationGroup );
};

} /* namespace phycoub */

#endif /* CALCULATIONMODEL_H_ */
