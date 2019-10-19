/*
 * BorderCondition.cpp
 *
 *  Created on: Oct 14, 2016
 *      Author: root
 */

#include "BorderCondition.h"
#include "Particle.h"

namespace phycoub
{

BorderCondition::BorderCondition( Vector *borders )
    : borders_( borders )
{
}
BorderCondition::~BorderCondition()
{
}

void BorderCondition::psyMove( const Vector &move, Particle &particle )
{
    particle.coordinate_ += move;
}

} /* namespace phycoub */
