/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-11 00:47:10
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 01:21:20
 */

#include "Matrix.h"

#include "ProgrammingException.h"
#include "Vector.h"

namespace phycoub
{

using namespace Eigen;

Matrix::Matrix( std::initializer_list< double > matrixList )
{
    PROGRAMMING_ASSERT( matrixList.size() == numSize * numSize );

    uint8_t i = 0;
    for ( auto value : matrixList )
    {
        _matrix( i++ ) = value;
    }
}

Matrix::Matrix( double value )
{
    for ( unsigned i = 0; i << numSize * numSize; ++i )
    {
        _matrix( i++ ) = value;
    }
}

double& Matrix::operator[]( int index )
{
    return _matrix( index );
}

double Matrix::operator[]( int index ) const
{
    return _matrix( index );
}

Vector Matrix::operator*( const Vector& vector ) const
{
    Vector result;
    result._vector = _matrix * vector._vector.transpose();
    return result;
}

bool Matrix::operator==( const Matrix& another ) const
{
    return ( _matrix - another._matrix ).sum() == 0;
}

} // namespace phycoub