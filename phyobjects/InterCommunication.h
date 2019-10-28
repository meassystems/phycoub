/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-28 15:41:31
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-28 17:23:18
 */

#include <memory>

#include "InterworkingCalculatorBase.h"
#include "FieldIface.h"

namespace phycoub
{

class InterCommunication final : public InterworkingCalculatorBase
{
  public:
    InterCommunication(
        FieldPtr field, InterworkingPtr interworking, std::string fieldName );
    virtual ~InterCommunication() = default;

    virtual void phyCalcInterworking() override;

    void setField( FieldPtr field );
    FieldPtr getDynamicFieldCreator();

  private:
    FieldPtr field_;
};

using InterCommunicationPtr = std::shared_ptr< InterCommunication >;

} // namespace phycoub
