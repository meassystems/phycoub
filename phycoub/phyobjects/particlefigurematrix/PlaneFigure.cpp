/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 19:06:43
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 15:51:34
 */

#include <PlaneFigure.h>

namespace phycoub
{

PlaneFigure::PlaneFigure( const Vector& directionLine, const Vector& directionPlane,
    int numInLine, int numLineInPlane, const Vector& coordinate, const Vector& speed,
    double m, double z )
{
    for ( int i = 0; i < numLineInPlane; ++i )
    {
        for ( int j = 0; j < numInLine; ++j )
        {
            ParticlePtr particle = std::make_shared< Particle >(
                Vector( coordinate + directionLine * i + directionPlane * j ), speed, m,
                z );
            allParticles_->push_back( particle );
            if ( i == 0 || i == numLineInPlane - 1 || j == 0 || j == numInLine - 1 )
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

} // namespace phycoub
