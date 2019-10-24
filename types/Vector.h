/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 21:35:42
 * @Last Modified by:   Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-23 21:35:42
 */

#pragma once

namespace phycoub
{
/*
 * Класс вектора в трехмерном пространстве.
 */
class Vector
{
  public:
    Vector();
    explicit Vector( double v );
    Vector( double x, double y, double z );
    virtual ~Vector() = default;

    Vector& operator=( const double& vector );
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
    Vector operator+( const double& value ) const;
    Vector operator-( const double& value ) const;
    Vector operator*( const double& value ) const;
    Vector operator/( const double& value ) const;
    Vector& operator+=( const double& value );
    Vector& operator-=( const double& value );
    Vector& operator*=( const double& value );
    Vector& operator/=( const double& value );
    bool operator==( const double& value ) const;
    bool operator>( const double& value ) const;
    bool operator<( const double& value ) const;
    bool operator>=( const double& value ) const;
    bool operator<=( const double& value ) const;
    //-----------------------------------------
    double& operator[]( int index );
    double operator[]( int index ) const;

    double getModule() const;
    bool below( const Vector& vector ) const;
    bool beyond( const Vector& vector ) const;

    double x_, y_, z_;
};

} /* namespace phycoub */
