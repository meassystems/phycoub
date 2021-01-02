/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 22:11:21
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-29 14:50:08
 */

#pragma once

#include <vector>
#include <list>
#include <string>
#include <memory>

#include "InterworkingCalculatorBase.h"
#include "Vector.h"

namespace phycoub
{

class CalculationModel;
/*
 * Класс/объект моделируемого пространства - группа частиц реагирующих на поле.
 */
class FieldReceiver final : public InterworkingCalculatorBase
{
  public:
    FieldReceiver( FieldCreatorPtr fieldCreator, InterworkingPtr interworking,
        std::string fieldName );
    virtual ~FieldReceiver() = default;

    virtual void phyCalcInterworking() override;

    void setFieldCreator( FieldCreatorPtr fieldCreator );
    FieldCreatorPtr getFieldCreator();

  private:
    FieldCreatorPtr fieldCreator_;
};

using FieldReceiverPtr = std::shared_ptr< FieldReceiver >;

} // namespace phycoub
