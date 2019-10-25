/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 22:09:51
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 14:28:21
 */

#pragma once

#include <vector>
#include <string>
#include <memory>

#include "CreateFieldBase.h"
#include "Vector.h"
#include "Particle.h"
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

    void addParticle( Particle* particle );
    void addGroupParticle( std::vector< Particle* >& particles );
    void removeParticle( Particle* particle );

    std::vector< Particle* > particles_;
    FieldFunction* functionField_;
    BorderFieldCondition* borderFieldCondition_;
};

using CreateFieldPtr = std::shared_ptr< CreateField >;

} /* namespace phycoub */
