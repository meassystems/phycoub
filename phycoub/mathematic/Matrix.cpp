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

Matrix::Matrix( std::initializer_list< double > matrixList )
{
    PROGRAMMING_ASSERT( matrixList.size() == numSize * numSize );

    uint8_t i = 0;
    for ( auto value : matrixList )
    {
        matrix_[ i++ ] = value;
    }
}

Matrix::Matrix( double value )
{
    for ( auto& matrixElement : matrix_ )
    {
        matrixElement = value;
    }
}

double& Matrix::operator[]( int index )
{
    return matrix_[ index ];
}

double Matrix::operator[]( int index ) const
{
    return matrix_[ index ];
}

Vector Matrix::operator*( const Vector& vector ) const
{
    Vector result;
    for ( uint8_t i = 0; i < numSize; ++i )
    {
        for ( uint8_t j = 0; j < numSize; ++j )
        {
            result[ i ] += vector[ j ] * matrix_[ i * numSize + j ];
        }
    }

    return result;
}

bool Matrix::operator==( const Matrix& another ) const
{
    for ( uint8_t i = 0; i < numSize * numSize; ++i )
    {
        if ( matrix_[ i ] != another[ i ] )
        {
            return false;
        }
    }

    return true;
}

} // namespace phycoub