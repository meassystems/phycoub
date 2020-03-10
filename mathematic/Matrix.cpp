/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-11 00:47:10
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 01:21:20
 */

#include "Matrix.h"

#include "Vector.h"

namespace phycoub
{

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
    for ( uint32_t i = 0; i < numSize; ++i )
    {
        for ( uint32_t j = 0; j < numSize; ++j )
        {
            result[ i ] += vector[ j ] * matrix_[ i * numSize + j ];
        }
    }

    return result;
}

} // namespace phycoub