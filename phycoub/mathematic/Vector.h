/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 21:35:42
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 01:34:24
 */

#pragma once

#include <stdint.h>

namespace phycoub
{

class Matrix;

/*
 * Класс вектора в трехмерном пространстве.
 */
class Vector final
{
  public:
    Vector() = default;
    ~Vector() = default;

    explicit Vector( double v );
    Vector( double x, double y, double z );

    Vector& operator=( double vector );
    //-----------------------------------------
    Vector operator+( const Vector& vector ) const;
    Vector operator-( const Vector& vector ) const;
    Vector operator*( const Vector& vector ) const;
    Vector& operator+=( const Vector& vector );
    Vector& operator-=( const Vector& vector );
    Vector& operator*=( const Vector& vector );
    bool operator==( const Vector& vector ) const;
    bool operator>( const Vector& vector ) const;
    bool operator<( const Vector& vector ) const;
    bool operator>=( const Vector& vector ) const;
    bool operator<=( const Vector& vector ) const;
    //-----------------------------------------
    Vector operator+( double value ) const;
    Vector operator-( double value ) const;
    Vector operator*( double value ) const;
    Vector operator/( double value ) const;
    Vector& operator+=( double value );
    Vector& operator-=( double value );
    Vector& operator*=( double value );
    Vector& operator/=( double value );
    bool operator==( double value ) const;
    bool operator>( double value ) const;
    bool operator<( double value ) const;
    bool operator>=( double value ) const;
    bool operator<=( double value ) const;
    //-----------------------------------------
    double& operator[]( int index );
    double operator[]( int index ) const;
    //-----------------------------------------
    Vector operator*( const Matrix& matrix ) const;

    double getModule() const;
    bool below( const Vector& vector ) const;
    bool beyond( const Vector& vector ) const;

    static constexpr uint32_t numSize = 3;

  public:
#pragma pack( push, 1 )
    union
    {
        double vector_[ numSize ] = { .0, 0., 0. };
        struct
        {
            double x_;
            double y_;
            double z_;
        };
    };
#pragma pack( pop )
};

} // namespace phycoub
