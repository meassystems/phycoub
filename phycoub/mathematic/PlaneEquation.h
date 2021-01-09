#pragma once

#include <Eigen/Dense>

namespace phycoub
{

struct PlaneEquation final
{
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    PlaneEquation( double A, double B, double C, double D )
    {
        _equation << A, B, C, D;
    }

    Eigen::Matrix< double, 1, 4, Eigen::RowMajor > _equation;
};

} // namespace phycoub