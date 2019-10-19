/*
 * ElectricFieldFunction.cpp
 *
 *  Created on: 17 ���. 2016 �.
 *      Author: SFrancishkov
 */

#include "ElectricFieldFunction.h"
#include "math.h"

namespace phycoub
{

ElectricFieldFunction::ElectricFieldFunction( double e, double mb, double vb, double lb )
    : FieldFunction()
    , e_( e )
    , mb_( mb )
    , vb_( vb )
    , lb_( lb )
{
}
ElectricFieldFunction::~ElectricFieldFunction()
{
}

Vector ElectricFieldFunction::psyField( const Particle &source, const Vector &mark )
{
    Vector effect;
    Vector distance = ( mark - source.coordinate_ );
    if ( distance == 0. )
    {
        return effect;
    }
    double coef = pow( e_, 2 ) / ( mb_ * lb_ * pow( vb_, 2 ) );

    effect = distance * ( ( coef * source.z_ ) / pow( distance.getModule(), 3 ) );

    return effect;
}
/*
void ElectricFieldFunction::psyField(const Particle& source, const Particle& mark) {
        Vector effect;
        Vector distance = (mark.coordinate_ - source.coordinate_);
        if(distance == 0.) {
                return;
        }
        double coef = pow(e_, 2) / (mb_ * lb_ * pow(vb_, 2));

        effect = distance * ((coef * source.z_) / pow(distance.getModule(), 3));

        mark.field_ += effect;
        source.field_ -=effect;
}
*/
} /* namespace phycoub */
