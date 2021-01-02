/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:59:29
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 15:51:17
 */

#include <ParallelepipedFigure.h>

namespace phycoub
{

ParallelepipedFigure::ParallelepipedFigure( const Vector& directionLine,
    const Vector& directionPlane, const Vector& directionParallelepiped, int numInLine,
    int numLineInPlane, int numPlaneInParallelepiped, const Vector& coordinate,
    const Vector& speed, double m, double z )
{
    for ( int k = 0; k < numPlaneInParallelepiped; ++k )
    {
        for ( int i = 0; i < numLineInPlane; ++i )
        {
            for ( int j = 0; j < numInLine; ++j )
            {
                ParticlePtr particle = std::make_shared< Particle >(
                    Vector( coordinate + directionParallelepiped * k + directionLine * i
                        + directionPlane * j ),
                    speed, m, z );

                allParticles_->push_back( particle );
                if ( k == 0 || k == numPlaneInParallelepiped - 1 || i == 0
                    || i == numLineInPlane - 1 || j == 0 || j == numInLine - 1 )
                {
                    borderParticles_->push_back( particle );
                }
                else
                {
                    centrallParticles_->push_back( particle );
                }
            }
        }
    }
}

} // namespace phycoub
