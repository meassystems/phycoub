/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 16:30:04
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-10 20:53:36
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
    static double scalarMultiplication( const Vector& first, const Vector& second );
    static double projectionToVector( const Vector& distance, const Vector& source );
    static double getCosBetweenVectors( const Vector& first, const Vector& second );

    static Vector calculatePerpendicular( const Vector& nVector );
    static Vector calculatePerpendicular( const Vector& nVector, const Vector& vVector );
};

} // namespace phycoub