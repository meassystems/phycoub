/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 22:09:51
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 09:44:07
 */

#pragma once

#include <vector>
#include <string>
#include <memory>

#include "CreateFieldBase.h"
#include "BorderFieldCondition.h"
#include "Vector.h"
#include "ParticleGroup.h"
#include "FieldFunction.h"

namespace phycoub
{

class BorderFieldCondition;
/*
 * Класс/объект моделируемого пространства - группа частиц создающих поле.
 */
class CreateField : public CreateFieldBase
{
  public:
    CreateField( FieldFunctionPtr functionField,
        BorderFieldConditionPtr borderFieldCondition, const std::string& fieldName );
    virtual ~CreateField() = default;

    virtual Vector getFieldInMark( const Vector& mark );

    void addGroupParticle( ParticleGroupPtr particles );

    void setFunctionField( FieldFunctionPtr fieldFunction );
    FieldFunctionPtr getFieldFunction();

    void setBorderFieldCondition( BorderFieldConditionPtr borderFieldCondition );
    BorderFieldConditionPtr getBorderFieldCondition();

  private:
    ParticleGroupList particleGroupList_;
    FieldFunctionPtr fieldFunction_;
    BorderFieldConditionPtr borderFieldCondition_;
};

using CreateFieldPtr = std::shared_ptr< CreateField >;

} /* namespace phycoub */
