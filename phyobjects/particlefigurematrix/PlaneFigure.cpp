/*
 * PlaneFigure.cpp
 *
 *  Created on: Dec 22, 2016
 *      Author: root
 */

#include <PlaneFigure.h>

namespace phycoub
{

PlaneFigure::PlaneFigure( const Vector &directionLine, const Vector &directionPlane,
    const int &numInLine, const int &numLineInPlane, const Vector &coordinate,
    const Vector &speed, const double &m, const double &z,
    BorderCondition *borderCondition )
{
    allParticles_.reserve( numInLine * numLineInPlane );
    for ( int i = 0; i < numLineInPlane; ++i )
    {
        for ( int j = 0; j < numInLine; ++j )
        {
            allParticles_.push_back( new Particle(
                Vector( coordinate + directionLine * i + directionPlane * j ), speed, m,
                z, borderCondition ) );
            if ( i == 0 || i == numLineInPlane - 1 || j == 0 || j == numInLine - 1 )
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
PlaneFigure::~PlaneFigure()
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
