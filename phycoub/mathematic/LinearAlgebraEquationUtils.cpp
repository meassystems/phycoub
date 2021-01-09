#include "LinearAlgebraEquationUtils.h"

#include <Eigen/Dense>

namespace phycoub
{

using namespace Eigen;

template< typename ResultType >
LAECalculationResult< ResultType >::LAECalculationResult( ResultType theResult )
    : decisionExist( true )
    , result( theResult )
{
}

// static
template< typename ResultType >
LAECalculationResult< ResultType > LAECalculationResult< ResultType >::decisionNotExist()
{
    return LAECalculationResult();
}

// static
LAECalculationResult< Vector >
LinearAlgebraEquationUtils::findStraightLineAndPlaneIntersectionPoint(
    const StraightLineEquation& straightLineEquation, const PlaneEquation& planeEquation )
{
    Eigen::Matrix< double, 3, 4, RowMajor > slae;
    slae.row( 0 ) = planeEquation._equation;
    slae.row( 1 ) = straightLineEquation._planeEquation1._equation;
    slae.row( 2 ) = straightLineEquation._planeEquation2._equation;

    const double normRow1 = slae.row( 0 ).norm();
    const double normRow2 = slae.row( 1 ).norm();
    const double normRow3 = slae.row( 2 ).norm();

    if ( normRow1 == 0. || normRow2 == 0. || normRow3 == 0. )
    {
        return LAECalculationResult< Vector >::decisionNotExist();
    }

    Eigen::Matrix< double, 3, 3, RowMajor > mainSlae = slae.topLeftCorner( 3, 3 );

    const double cosEq1
        = ( mainSlae.row( 0 ) + mainSlae.row( 1 ) ).sum() / normRow1 / normRow2;
    const double cosEq2
        = ( mainSlae.row( 0 ) + mainSlae.row( 2 ) ).sum() / normRow1 / normRow3;

    if ( abs( cosEq1 ) == 1. || abs( cosEq2 ) == 1. )
    {
        return LAECalculationResult< Vector >::decisionNotExist();
    }

    const double mainDet = mainSlae.determinant();
    if ( mainDet == 0. )
    {
        return LAECalculationResult< Vector >::decisionNotExist();
    }

    Eigen::Matrix< double, 3, 3, RowMajor > xSlae = mainSlae;
    xSlae.col( 0 ) = slae.col( 3 ) * -1;
    const double xDet = xSlae.determinant();

    Eigen::Matrix< double, 3, 3, RowMajor > ySlae = mainSlae;
    ySlae.col( 1 ) = slae.col( 3 ) * -1;
    const double yDet = ySlae.determinant();

    Eigen::Matrix< double, 3, 3, RowMajor > zSlae = mainSlae;
    zSlae.col( 2 ) = slae.col( 3 ) * -1;
    const double zDet = zSlae.determinant();

    Vector result{ xDet / mainDet, yDet / mainDet, zDet / mainDet };
    return LAECalculationResult< Vector >( result );
}

} // namespace phycoub
