/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-11 00:35:24
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 01:21:12
 */

#include <stdint.h>
#include <Eigen/Dense>

namespace phycoub
{

class Vector;

class Matrix final
{
  public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    Matrix();
    ~Matrix() = default;

    Matrix( std::initializer_list< double > matrixList );
    Matrix( double value );

    double& operator[]( int index );
    double operator[]( int index ) const;

    Vector operator*( const Vector& vector ) const;
    bool operator==( const Matrix& another ) const;

    static constexpr uint32_t numSize = 3;
    Eigen::Matrix< double, numSize, numSize, Eigen::RowMajor > _matrix;
};

} // namespace phycoub