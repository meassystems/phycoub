/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 22:11:21
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 23:05:27
 */

#pragma once

#include <vector>
#include <list>
#include <string>
#include <memory>

#include "InterworkingFunction.h"
#include "CreateFieldBase.h"
#include "Vector.h"
#include "ParticleGroup.h"

namespace phycoub
{

class CalculationModel;
/*
 * Класс/объект моделируемого пространства - группа частиц реагирующих на поле.
 */
class FeelField
{
  public:
    FeelField( CreateFieldBasePtr createField, InterworkingFunction* interworkingFunction,
        std::string fieldName );
    virtual ~FeelField() = default;

    virtual void phyCalcInterworking();

    void addGroupParticle( ParticleGroupPtr particles );

    CreateFieldBasePtr createField_;
    ParticleGroupList particleGroupList_;
    InterworkingFunction* interworkingFunction_;
    std::string fieldName_;
};

using FeelFieldPtr = std::shared_ptr< FeelField >;
using FeelFieldList = std::list< FeelFieldPtr >;

} // namespace phycoub
