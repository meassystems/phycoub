#pragma once

#include "PlaneEquation.h"

namespace phycoub
{

struct StraightLineEquation final
{
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    StraightLineEquation( const PlaneEquation& eq1, const PlaneEquation& eq2 )
        : _planeEquation1( eq1 )
        , _planeEquation2( eq2 )
    {
    }

    PlaneEquation _planeEquation1;
    PlaneEquation _planeEquation2;
};

} // namespace phycoub