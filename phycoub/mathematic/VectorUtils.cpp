/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 16:30:01
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-10 20:53:27
 */

#include "VectorUtils.h"

#include "Vector.h"
#include "MathExceptions.h"
#include "RandomUtils.h"
#include "ProgrammingException.h"

namespace phycoub
{

// static
Vector VectorUtils::normalizeVector( Vector vector )
{
    const double vectorModulo = vector.getModule();
    if ( vectorModulo == 0 )
    {
        return vector;
    }

    vector /= vectorModulo;
    return vector;
}

// static
double VectorUtils::scalarMultiplication( const Vector& first, const Vector& second )
{
    double result = first.x() * second.x() + first.y() * second.y() + first.z() * second.z();
    return result;
}

// static
double VectorUtils::projectionToVector( const Vector& distance, const Vector& source )
{
    double result = scalarMultiplication( distance, source ) / distance.getModule();
    return result;
}

// static
double VectorUtils::getCosBetweenVectors( const Vector& first, const Vector& second )
{
    double firstModulo = first.getModule();
    double secondModulo = second.getModule();

    if ( firstModulo == 0. || secondModulo == 0. )
    {
        throw DivisionByZeroException();
    }

    double scalar = scalarMultiplication( first, second );
    return scalar / ( firstModulo * secondModulo );
}

// static
Vector VectorUtils::calculatePerpendicular( const Vector& nVector )
{
    Vector v = RandomUtils::generateRandomNormalizedVector() + 1;

    if ( nVector.x() != 0 )
    {
        v.x() = -1 * ( nVector.y() * v.y() + nVector.z() * v.z() ) / nVector.x();
    }
    else if ( nVector.y() != 0 )
    {
        v.y() = -1 * ( nVector.x() * v.x() + nVector.z() * v.z() ) / nVector.y();
    }
    else if ( nVector.z() != 0 )
    {
        v.z() = -1 * ( nVector.x() * v.x() + nVector.y() * v.y() ) / nVector.z();
    }
    else
    {
        PROGRAMMING_ASSERT( false );
    }

    return VectorUtils::normalizeVector( v );
}

// static
Vector VectorUtils::calculatePerpendicular( const Vector& nVector, const Vector& vVector )
{
    unsigned nNotNullIndex = Vector::numSize;
    for ( unsigned i = 0; i < 3; ++i )
    {
        if ( nVector[ i ] != 0 )
        {
            nNotNullIndex = i;
            break;
        }
    }
    PROGRAMMING_ASSERT( nNotNullIndex < Vector::numSize );

    unsigned vNotNullIndex = Vector::numSize;
    for ( unsigned i = 0; i < 3; ++i )
    {
        if ( i != nNotNullIndex && vVector[ i ] != 0 )
        {
            vNotNullIndex = i;
            break;
        }
    }
    PROGRAMMING_ASSERT( vNotNullIndex < Vector::numSize );

    unsigned uRandIndex = 1 + 2 - nNotNullIndex - vNotNullIndex;
    const double nvCoeff = vVector[ nNotNullIndex ]
        / ( nVector[ nNotNullIndex ] * vVector[ vNotNullIndex ] );

    Vector u = RandomUtils::generateRandomNormalizedVector() + 1;

    u[ vNotNullIndex ] = u[ uRandIndex ]
        * ( nVector[ uRandIndex ] * nvCoeff
            - vVector[ uRandIndex ] / vVector[ vNotNullIndex ] )
        / ( 1 - nVector[ vNotNullIndex ] * nvCoeff );
    u[ nNotNullIndex ] = -1
        * ( u[ vNotNullIndex ] * nVector[ vNotNullIndex ]
            + u[ uRandIndex ] * nVector[ uRandIndex ] )
        / nVector[ nNotNullIndex ];

    return VectorUtils::normalizeVector( u );
}

} // namespace phycoub