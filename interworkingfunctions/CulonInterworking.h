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
    CulonInterworking() = default;
    virtual ~CulonInterworking() = default;

    const Vector psyForce( const Vector& field, const ParticlePtr particle ) override;
};

} /* namespace phycoub */

#endif /* CULONINTERWORKING_H_ */
