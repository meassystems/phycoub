/*
 * ElasticCoubCondition.h
 *
 *  Created on: 19 ���. 2016 �.
 *      Author: SFrancishkov
 */

#ifndef ELASTICCOUBCONDITION_H_
#define ELASTICCOUBCONDITION_H_

#include <BorderCondition.h>

namespace phycoub
{
/*
 * Упругие граничные условия в случае, если пространсво моделирования - прямоугольник.
 */
class ElasticCoubCondition : public BorderCondition
{
  public:
    ElasticCoubCondition( Vector *borders );
    virtual ~ElasticCoubCondition();

    void psyMove( const Vector &move, Particle &particle ) override;
};

} /* namespace phycoub */

#endif /* ELASTICCOUBCONDITION_H_ */
