/*
 * ParallelepipedFigure.cpp
 *
 *  Created on: Dec 28, 2016
 *      Author: root
 */

#include <ParallelepipedFigure.h>

namespace phycoub
{

ParallelepipedFigure::ParallelepipedFigure( const Vector &directionLine,
    const Vector &directionPlane, const Vector &directionParallelepiped,
    const int &numInLine, const int &numLineInPlane, const int &numPlaneInParallelepiped,
    const Vector &coordinate, const Vector &speed, const double &m, const double &z,
    BorderCondition *borderCondition )
{
    allParticles_.reserve( numInLine * numLineInPlane * numPlaneInParallelepiped );
    for ( int k = 0; k < numPlaneInParallelepiped; ++k )
    {
        for ( int i = 0; i < numLineInPlane; ++i )
        {
            for ( int j = 0; j < numInLine; ++j )
            {
                allParticles_.push_back(
                    new Particle( Vector( coordinate + directionParallelepiped * k
                                      + directionLine * i + directionPlane * j ),
                        speed, m, z, borderCondition ) );
                if ( k == 0 || k == numPlaneInParallelepiped - 1 || i == 0
                    || i == numLineInPlane - 1 || j == 0 || j == numInLine - 1 )
                {
                    borderParticles_.push_back( allParticles_.back() );
                }
                else
                {
                    centrallParticles_.push_back( allParticles_.back() );
                }
            }
        }
    }
}
ParallelepipedFigure::~ParallelepipedFigure()
{
    for ( unsigned int i = 0; i < allParticles_.size(); ++i )
    {
        delete allParticles_[ i ];
    }
    allParticles_.clear();
    borderParticles_.clear();
    centrallParticles_.clear();
}

} /* namespace phycoub */
