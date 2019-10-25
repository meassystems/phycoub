/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:05:52
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 22:46:47
 */

#include "BorderCondition.h"
#include "Particle.h"

namespace phycoub
{

BorderCondition::BorderCondition( Vector* borders )
    : borders_( borders )
{
}

void BorderCondition::psyMove( const Vector& move, ParticlePtr* particle )
{
    ( *particle )->coordinate_ += move;
    ( *particle )->moved();
}

} // namespace phycoub
