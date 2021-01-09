/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 21:35:42
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 01:34:24
 */

#pragma once

#include <stdint.h>
#include <Eigen/Dense>

namespace phycoub
{

class Matrix;

class Vector final
{
  public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    Vector();
    ~Vector() = default;

    Vector( double x, double y, double z );
    Vector( double v );

    double& x();
    double& y();
    double& z();

    double x() const;
    double y() const;
    double z() const;

    Vector& operator=( double v );
    //-----------------------------------------
    Vector operator+( const Vector& vector ) const;
    Vector operator-( const Vector& vector ) const;
    Vector operator*( const Vector& vector ) const;
    Vector& operator+=( const Vector& vector );
    Vector& operator-=( const Vector& vector );
    Vector& operator*=( const Vector& vector );
    bool operator==( const Vector& vector ) const;
    bool operator!=( const Vector& vector ) const;
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

    double getMax() const;


    static constexpr uint32_t numSize = 3;
    Eigen::Matrix< double, 1, numSize, Eigen::RowMajor > _vector;
};

} // namespace phycoub
