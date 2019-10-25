/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 22:09:51
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 19:19:21
 */

#pragma once

#include <vector>
#include <string>
#include <memory>

#include "CreateFieldBase.h"
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
    CreateField( FieldFunction* functionField, BorderFieldCondition* borderFieldCondition,
        const std::string& fieldName );
    virtual ~CreateField() = default;

    virtual Vector getFieldInMark( const Vector& mark );

    void addGroupParticle( ParticleGroupPtr particles );

    ParticleGroupList particleGroupList_;
    FieldFunction* functionField_;
    BorderFieldCondition* borderFieldCondition_;
};

using CreateFieldPtr = std::shared_ptr< CreateField >;

} /* namespace phycoub */
