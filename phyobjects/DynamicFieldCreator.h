/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 22:09:51
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 19:07:27
 */

#pragma once

#include <vector>
#include <string>
#include <memory>

#include "FieldCreator.h"
#include "BorderFieldCondition.h"
#include "Vector.h"
#include "ParticleGroup.h"
#include "FieldIface.h"

namespace phycoub
{

class BorderFieldCondition;
/*
 * Класс/объект моделируемого пространства - группа частиц создающих поле.
 */
class DynamicFieldCreator : public FieldCreator
{
  public:
    DynamicFieldCreator( FieldPtr field, BorderFieldConditionPtr borderFieldCondition,
        const std::string& fieldName );
    virtual ~DynamicFieldCreator() = default;

    virtual Vector getFieldInMark( const Vector& mark );

    void addGroupParticle( ParticleGroupPtr particles );

    void setFunctionField( FieldPtr fieldFunction );
    FieldPtr getFieldFunction();

    void setBorderFieldCondition( BorderFieldConditionPtr borderFieldCondition );
    BorderFieldConditionPtr getBorderFieldCondition();

  private:
    ParticleGroupList particleGroupList_;
    FieldPtr field_;
    BorderFieldConditionPtr borderFieldCondition_;
};

using DynamicFieldCreatorPtr = std::shared_ptr< DynamicFieldCreator >;

} /* namespace phycoub */
