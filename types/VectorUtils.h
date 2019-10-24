/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 16:30:04
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-23 21:39:36
 */

#pragma once

namespace phycoub
{

class Vector;

class VectorUtils final
{
  public:
    VectorUtils() = delete;

    static Vector normalizeVector( Vector vector );
    static Vector vectorMultiplication( const Vector& first, const Vector& second );
};

} // namespace phycoub