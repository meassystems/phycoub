/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-26 10:24:16
 * @Last Modified by:   Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 10:24:16
 */

#include <LDFieldFunction.h>

#include <math.h>

namespace phycoub
{

LDFieldFunction::LDFieldFunction( double a, double b, double eps )
    : a_( a )
    , b_( b )
    , eps_( eps )
{
}

// virtual override
Vector LDFieldFunction::psyField(
    const Vector& mark, const ParticlePtr particle /* = nullptr*/ ) const
{
    Vector effect;
    Vector distance = ( mark - particle->coordinate_ );
    if ( distance == 0. )
    {
        return effect;
    }

    effect = distance
        * ( -24 * eps_ / pow( a_, 2 )
              * ( pow( a_ / distance.getModule(), 8 )
                    - 2 * pow( b_ / distance.getModule(), 14 ) ) );

    return effect;
}

} // namespace phycoub
