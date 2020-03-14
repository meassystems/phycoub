/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-26 08:23:20
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-14 16:41:08
 */

#include "CyclicBorder.h"

#include <math.h>

#include "Particle.h"
#include "Utils.h"

namespace phycoub
{

CyclicBorder::CyclicBorder( const Vector& borders )
    : CubicShape( borders )
{
    minBorderSize = std::min( std::min( borders.x_, borders.y_ ), borders.z_ );
}

// virtual override
void CyclicBorder::psyMove(
    const Vector& move, const Vector& speed, ParticlePtr* particle )
{
    bool isBorderReached = false;
    const Vector& borders = getBorders();
    Vector coordinate = ( *particle )->getCoordinate() + move;

    for ( int i = 0; i < 3; ++i )
    {
        if ( coordinate[ i ] < 0 )
        {
            coordinate[ i ] += borders[ i ];
            isBorderReached = true;
        }
        else if ( coordinate[ i ] > borders[ i ] )
        {
            coordinate[ i ] -= borders[ i ];
            isBorderReached = true;
        }
    }

    moveParticle( coordinate, speed, isBorderReached, particle );

    const double moveModule = move.getModule();

    LogPtr log = getLog();
    if ( log && ( moveModule >= minBorderSize * 0.05 || isnan( moveModule ) ) )
    {
        log->writeMessage(
            Utils::formatString(
                "Particle[%lu] changes its coordinate by an amount "
                "greater than the 5%% size of the cube. Try to reduce 'dt'",
                ( *particle )->getId() ),
            LogLevel::error );
    }
}

} // namespace phycoub
