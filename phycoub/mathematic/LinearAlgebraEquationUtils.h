#pragma once

#include "Vector.h"
#include "StraightLineEquation.h"

namespace phycoub
{

template< typename ResultType >
struct LAECalculationResult
{
    LAECalculationResult() = default;
    LAECalculationResult(ResultType theResult);
    static LAECalculationResult decisionNotExist();

    bool decisionExist = false;
    ResultType result;
};

class LinearAlgebraEquationUtils final
{
  public:
    LinearAlgebraEquationUtils() = delete;

    static LAECalculationResult< Vector > findStraightLineAndPlaneIntersectionPoint(
        const StraightLineEquation& straightLineEquation,
        const PlaneEquation& planeEquation );
};

} // namespace phycoub