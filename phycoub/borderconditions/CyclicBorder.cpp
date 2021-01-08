/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-26 08:23:20
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-16 01:28:50
 */

#include "CyclicBorder.h"

#include <math.h>
#include <algorithm>

#include "Particle.h"
#include "Utils.h"
#include "ErrorCode.h"

namespace phycoub
{

CyclicBorder::CyclicBorder( const Vector& borders )
    : CubicShape( borders )
{
    minBorderSize = std::min( std::min( borders.x(), borders.y() ), borders.z() );
}

// virtual override
void CyclicBorder::psyMove(
    const Vector& move, const Vector& speed, ParticlePtr particle )
{
    bool isBorderReached = false;
    const Vector& borders = getBorders();
    Vector coordinate = particle->getCoordinate() + move;

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

    if ( isBorderReached )
    {
        borderReached( particle );
    }

    moveParticle( coordinate, speed, isBorderReached, particle );

    LogPtr log = getLog();
    const double moveModule = move.getModule();

    if ( log && ( moveModule >= minBorderSize * 0.05 || isnan( moveModule ) ) )
    {
        log->writeMessage( ErrorCode::borderConditionsCoordinateGreaterChange,
            LogLevel::error, particle->getId() );
    }
}

} // namespace phycoub
