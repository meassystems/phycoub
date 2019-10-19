/*
 * CulonInterworking.h
 *
 *  Created on: Oct 14, 2016
 *      Author: root
 */

#ifndef CULONINTERWORKING_H_
#define CULONINTERWORKING_H_

#include <InterworkingFunction.h>

namespace phycoub
{
/*
 * Кулоновская сила
 */
class CulonInterworking : public InterworkingFunction
{
  public:
    CulonInterworking();
    virtual ~CulonInterworking();

    const Vector psyForce( const Vector &field, const Particle *particle );
};

} /* namespace phycoub */

#endif /* CULONINTERWORKING_H_ */
