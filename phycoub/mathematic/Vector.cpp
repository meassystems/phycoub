/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 21:35:24
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 01:22:35
 */

#include "Vector.h"
#include "Matrix.h"

namespace phycoub
{

using namespace Eigen;

Vector::Vector()
{
    _vector << 0, 0, 0;
}

Vector::Vector( double x, double y, double z )
{
    _vector << x, y, z;
}

Vector::Vector( double v )
{
    _vector << v, v, v;
}

double& Vector::x()
{
    return _vector( 0 );
}

double& Vector::y()
{
    return _vector( 1 );
}

double& Vector::z()
{
    return _vector( 2 );
}

double Vector::x() const
{
    return _vector( 0 );
}

double Vector::y() const
{
    return _vector( 1 );
}

double Vector::z() const
{
    return _vector( 2 );
}

Vector& Vector::operator=( double v )
{
    if(std::isnan(v))
    {
        unsigned debug = 0;
    }

    _vector << v, v, v;
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
    _vector += vector._vector;

    if(std::isnan(_vector.x()) || std::isnan(_vector.y()) || std::isnan(_vector.z()))
    {
        unsigned debug = 0;
    }

    return *this;
}

Vector& Vector::operator-=( const Vector& vector )
{
    _vector -= vector._vector;

    if(std::isnan(_vector.x()) || std::isnan(_vector.y()) || std::isnan(_vector.z()))
    {
        unsigned debug = 0;
    }

    return *this;
}

Vector& Vector::operator*=( const Vector& vector )
{
    _vector = _vector.cross( vector._vector ).eval();

    if(std::isnan(_vector.x()) || std::isnan(_vector.y()) || std::isnan(_vector.z()))
    {
        unsigned debug = 0;
    }

    return *this;
}

bool Vector::operator==( const Vector& vector ) const
{
    return ( _vector - vector._vector ).sum() == 0.;
}

bool Vector::operator!=( const Vector& vector ) const
{
    return !operator==( vector );
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
    _vector = _vector.array() + value;

    if(std::isnan(_vector.x()) || std::isnan(_vector.y()) || std::isnan(_vector.z()))
    {
        unsigned debug = 0;
    }

    return *this;
}

Vector& Vector::operator-=( double value )
{
    _vector = _vector.array() - value;

    if(std::isnan(_vector.x()) || std::isnan(_vector.y()) || std::isnan(_vector.z()))
    {
        unsigned debug = 0;
    }

    return *this;
}

Vector& Vector::operator*=( double value )
{
    _vector = _vector.array() * value;

    if(std::isnan(_vector.x()) || std::isnan(_vector.y()) || std::isnan(_vector.z()))
    {
        unsigned debug = 0;
    }

    return *this;
}

Vector& Vector::operator/=( double value )
{
    _vector = _vector.array() / value;

    if(std::isnan(_vector.x()) || std::isnan(_vector.y()) || std::isnan(_vector.z()))
    {
        unsigned debug = 0;
    }

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
            return _vector( 0 );
        case 1:
            return _vector( 1 );
        case 2:
            return _vector( 2 );
        default:
            throw "Error, index by bounds";
    }
}

double Vector::operator[]( int index ) const
{
    switch ( index )
    {
        case 0:
            return _vector( 0 );
        case 1:
            return _vector( 1 );
        case 2:
            return _vector( 2 );
        default:
            throw "Error, index by bounds";
    }
}

Vector Vector::operator*( const Matrix& matrix ) const
{
    Vector result;
    result._vector = _vector * matrix._matrix;
    return result;
}

double Vector::getModule() const
{
    return _vector.norm();
}

bool Vector::below( const Vector& vector ) const
{
    return !( x() >= vector.x() && y() >= vector.y() && z() >= vector.z() );
}

bool Vector::beyond( const Vector& vector ) const
{
    return !( x() <= vector.x() && y() <= vector.y() && z() <= vector.z() );
}

double Vector::getMax() const
{
    return _vector.maxCoeff();
}

} // namespace phycoub
