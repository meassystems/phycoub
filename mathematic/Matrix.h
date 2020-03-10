/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-11 00:35:24
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 01:21:12
 */

#include <stdint.h>
#include <array>

namespace phycoub
{

class Vector;

class Matrix final
{
  public:
    Matrix() = default;
    ~Matrix() = default;

    explicit Matrix( double value );

    double& operator[]( int index );
    double operator[]( int index ) const;

    Vector operator*( const Vector& vector ) const;

  private:
    static constexpr uint32_t numSize = 3;
    std::array< double, numSize* numSize > matrix_ = { 0. };
};

} // namespace phycoub