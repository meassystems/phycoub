/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 22:11:21
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 12:49:10
 */

#pragma once

#include <vector>
#include <string>
#include <memory>

#include "InterworkingFunction.h"
#include "CreateFieldBase.h"
#include "Vector.h"
#include "Particle.h"

namespace phycoub
{

class CalculationModel;
/*
 * Класс/объект моделируемого пространства - группа частиц реагирующих на поле.
 */
class FeelField
{
  public:
    FeelField( CreateFieldBase* createField, InterworkingFunction* interworkingFunction,
        std::string fieldName );
    virtual ~FeelField();

    virtual void phyCalcInterworking();

    void addParticle( Particle* particle );
    void addGroupParticle( std::vector< Particle* >& particles );
    void removeParticle( Particle* particle );

    CreateFieldBase* createField_;
    std::vector< Particle* > particles_;
    InterworkingFunction* interworkingFunction_;
    std::string fieldName_;
};

using FeelFieldPtr = std::shared_ptr< FeelField >;

} // namespace phycoub
