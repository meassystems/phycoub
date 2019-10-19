/*
 * CyclicBorder.h
 *
 *  Created on: 20 дек. 2016 г.
 *      Author: serv
 */

#ifndef CYCLICBORDER_H_
#define CYCLICBORDER_H_

#include <BorderCondition.h>

namespace phycoub
{

class CyclicBorder : public BorderCondition
{
  public:
    CyclicBorder( Vector *borders );
    virtual ~CyclicBorder();

    virtual void psyMove( const Vector &move, Particle &particle );
};

} /* namespace phycoub */

#endif /* CYCLICBORDER_H_ */
