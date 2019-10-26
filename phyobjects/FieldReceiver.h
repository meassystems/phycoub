/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 22:11:21
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 19:04:58
 */

#pragma once

#include <vector>
#include <list>
#include <string>
#include <memory>

#include "InterworkingIface.h"
#include "FieldCreator.h"
#include "Vector.h"
#include "ParticleGroup.h"

namespace phycoub
{

class CalculationModel;
/*
 * Класс/объект моделируемого пространства - группа частиц реагирующих на поле.
 */
class FieldReceiver
{
  public:
    FieldReceiver( FieldCreatorPtr fieldCreator, InterworkingPtr interworking,
        std::string fieldName );
    virtual ~FieldReceiver() = default;

    virtual void phyCalcInterworking();

    void addGroupParticle( ParticleGroupPtr particles );

    void setFieldCreator( FieldCreatorPtr fieldCreator );
    FieldCreatorPtr getFieldCreator();

    void setInterworkingFunction( InterworkingPtr interworkingFunction );
    InterworkingPtr getInterworkingFunction();

  private:
    FieldCreatorPtr fieldCreator_;
    InterworkingPtr interworking_;
    ParticleGroupList particleGroupList_;
    std::string fieldName_;
};

using FieldReceiverPtr = std::shared_ptr< FieldReceiver >;
using FieldReceiverList = std::list< FieldReceiverPtr >;

} // namespace phycoub
