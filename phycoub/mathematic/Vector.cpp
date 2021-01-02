/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 21:35:24
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 01:22:35
 */

#include "Vector.h"

#include <math.h>

#include "Matrix.h"

namespace phycoub
{

Vector::Vector( double v )
    : x_( v )
    , y_( v )
    , z_( v )
{
}

Vector::Vector( double x, double y, double z )
    : x_( x )
    , y_( y )
    , z_( z )
{
}

Vector& Vector::operator=( double vector )
{
    x_ = vector;
    y_ = vector;
    z_ = vector;

    return *this;
}

Vector Vector::operator+( const Vector& vector ) const
{
    Vector copy = *this;
    copy += vector;

    return copy;
}

Vector Vector::operator-( const Vector& vector ) const
{
    Vector copy = *this;
    copy -= vector;

    return copy;
}

Vector Vector::operator*( const Vector& vector ) const
{
    Vector copy = *this;
    copy *= vector;

    return copy;
}

Vector& Vector::operator+=( const Vector& vector )
{
    x_ += vector.x_;
    y_ += vector.y_;
    z_ += vector.z_;

    return *this;
}

Vector& Vector::operator-=( const Vector& vector )
{
    x_ -= vector.x_;
    y_ -= vector.y_;
    z_ -= vector.z_;

    return *this;
}

Vector& Vector::operator*=( const Vector& vector )
{
    const double x = x_;
    x_ = ( y_ * vector.z_ ) - ( z_ * vector.y_ );

    const double y = y_;
    y_ = ( z_ * vector.x_ ) - ( x * vector.z_ );

    z_ = ( x * vector.y_ ) - ( y * vector.x_ );

    return *this;
}

bool Vector::operator==( const Vector& vector ) const
{
    return x_ == vector.x_ && y_ == vector.y_ && z_ == vector.z_;
}

bool Vector::operator>( const Vector& vector ) const
{
    return getModule() > vector.getModule();
}

bool Vector::operator<( const Vector& vector ) const
{
    return getModule() < vector.getModule();
}

bool Vector::operator>=( const Vector& vector ) const
{
    return getModule() >= vector.getModule();
}

bool Vector::operator<=( const Vector& vector ) const
{
    return getModule() <= vector.getModule();
}

//-----------------------------------------------------
Vector Vector::operator+( double value ) const
{
    Vector copy = *this;
    copy += value;

    return copy;
}

Vector Vector::operator-( double value ) const
{
    Vector copy = *this;
    copy -= value;

    return copy;
}

Vector Vector::operator*( double value ) const
{
    Vector copy = *this;
    copy *= value;

    return copy;
}

Vector Vector::operator/( double value ) const
{
    Vector copy = *this;
    copy /= value;

    return copy;
}

Vector& Vector::operator+=( double value )
{
    x_ += value;
    y_ += value;
    z_ += value;

    return *this;
}

Vector& Vector::operator-=( double value )
{
    x_ -= value;
    y_ -= value;
    z_ -= value;

    return *this;
}

Vector& Vector::operator*=( double value )
{
    x_ *= value;
    y_ *= value;
    z_ *= value;

    return *this;
}

Vector& Vector::operator/=( double value )
{
    x_ /= value;
    y_ /= value;
    z_ /= value;

    return *this;
}

bool Vector::operator==( double value ) const
{
    return getModule() == value;
}

bool Vector::operator>( double value ) const
{
    return getModule() > value;
}

bool Vector::operator<( double value ) const
{
    return getModule() < value;
}

bool Vector::operator>=( double value ) const
{
    return getModule() >= value;
}

bool Vector::operator<=( double value ) const
{
    return getModule() <= value;
}

//---------------------------------------------------------
double& Vector::operator[]( int index )
{
    switch ( index )
    {
        case 0:
            return x_;
        case 1:
            return y_;
        case 2:
            return z_;
        default:
            throw "Error, index by bounds";
    }
}

double Vector::operator[]( int index ) const
{
    Vector copy = *this;
    return copy[ index ];
}

Vector Vector::operator*( const Matrix& matrix ) const
{
    Vector result;
    for ( uint32_t i = 0; i < numSize; ++i )
    {
        for ( uint32_t j = 0; j < numSize; ++j )
        {
            result[ i ] += vector_[ j ] * matrix[ j * numSize + i ];
        }
    }

    return result;
}

double Vector::getModule() const
{
    return sqrt( pow( x_, 2 ) + pow( y_, 2 ) + pow( z_, 2 ) );
}

bool Vector::below( const Vector& vector ) const
{
    return !( x_ >= vector.x_ && y_ >= vector.y_ && z_ >= vector.z_ );
}

bool Vector::beyond( const Vector& vector ) const
{
    return !( x_ <= vector.x_ && y_ <= vector.y_ && z_ <= vector.z_ );
}

} // namespace phycoub
