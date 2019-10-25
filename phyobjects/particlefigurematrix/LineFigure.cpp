/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:50:13
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 01:23:20
 */

#include <LineFigure.h>

namespace phycoub
{

LineFigure::LineFigure( ParticleGroupPtr particles )
    : particles_( particles )
{
}

LineFigure::LineFigure( const Vector& direction, int num,
    const Vector& coordinateFerstParticle, const Vector& speed, double m, double z )
{
    for ( int i = 0; i < num; ++i )
    {
        particles_->emplace_back( std::make_shared< Particle >(
            coordinateFerstParticle + direction * i, speed, m, z ) );
    }
}

} // namespace phycoub
