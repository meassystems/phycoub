/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-24 19:54:53
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 19:09:39
 */

#include <algorithm>

#include "CyclicBoundedField.h"
#include "DynamicFieldCreator.h"
#include "Particle.h"

namespace phycoub
{

CyclicBoundedField::CyclicBoundedField( const Vector& borders, double radiusCut )
    : radiusCut_( radiusCut )
    , borders_( borders )
{

    transferConst[ 0 ] = Vector( -borders_.x_, +borders_.y_, -borders_.z_ );
    transferConst[ 1 ] = Vector( -borders_.x_, 0, -borders_.z_ );
    transferConst[ 2 ] = Vector( -borders_.x_, -borders_.y_, -borders_.z_ );
    transferConst[ 3 ] = Vector( -borders_.x_, +borders_.y_, 0 );
    transferConst[ 4 ] = Vector( -borders_.x_, 0, 0 );
    transferConst[ 5 ] = Vector( -borders_.x_, -borders_.y_, 0 );
    transferConst[ 6 ] = Vector( -borders_.x_, +borders_.y_, +borders_.z_ );
    transferConst[ 7 ] = Vector( -borders_.x_, 0, +borders_.z_ );
    transferConst[ 8 ] = Vector( -borders_.x_, -borders_.y_, +borders_.z_ );
    //-------------------------------------------------------------------------
    transferConst[ 9 ] = Vector( 0, +borders_.y_, -borders_.z_ );
    transferConst[ 10 ] = Vector( 0, 0, -borders_.z_ );
    transferConst[ 11 ] = Vector( 0, -borders_.y_, -borders_.z_ );
    transferConst[ 12 ] = Vector( 0, +borders_.y_, 0 );
    transferConst[ 13 ] = Vector( 0, 0, 0 );
    transferConst[ 14 ] = Vector( 0, -borders_.y_, 0 );
    transferConst[ 15 ] = Vector( 0, +borders_.y_, +borders_.z_ );
    transferConst[ 16 ] = Vector( 0, 0, +borders_.z_ );
    transferConst[ 17 ] = Vector( 0, -borders_.y_, +borders_.z_ );
    //-------------------------------------------------------------------------
    transferConst[ 18 ] = Vector( +borders_.x_, +borders_.y_, -borders_.z_ );
    transferConst[ 19 ] = Vector( +borders_.x_, 0, -borders_.z_ );
    transferConst[ 20 ] = Vector( +borders_.x_, -borders_.y_, -borders_.z_ );
    transferConst[ 21 ] = Vector( +borders_.x_, +borders_.y_, 0 );
    transferConst[ 22 ] = Vector( +borders_.x_, 0, 0 );
    transferConst[ 23 ] = Vector( +borders_.x_, -borders_.y_, 0 );
    transferConst[ 24 ] = Vector( +borders_.x_, +borders_.y_, +borders_.z_ );
    transferConst[ 25 ] = Vector( +borders_.x_, 0, +borders_.z_ );
    transferConst[ 26 ] = Vector( +borders_.x_, -borders_.y_, +borders_.z_ );
}

// virtual override
Vector CyclicBoundedField::phyFieldWithBorderCondition(
    FieldPtr field, const ParticlePtr particle, const Vector& mark )
{
    // todo validate this algorithm
    const Vector& coordinate = particle->getCoordinate();

    Vector result;
    if ( ( mark - radiusCut_ ).beyond( Vector( 0., 0., 0. ) )
        && ( mark + radiusCut_ ).below( borders_ ) )
    {
        if ( coordinate.beyond( mark - radiusCut_ )
            && coordinate.below( mark + radiusCut_ ) )
        {
            result = field->psyField( mark, particle );
        }
    }
    else
    {
        for ( int i = 0; i < 6; ++i )
        {
            intersection[ i ] = false;
        }
        transferQuantity = 0;
        //-----
        if ( ( mark.x_ - radiusCut_ ) < 0 )
        {
            intersection[ 0 ] = true;
            addTransfer( 5 - 1 );
        }
        else if ( ( mark.x_ + radiusCut_ ) > borders_.x_ )
        {
            intersection[ 5 ] = true;
            addTransfer( 23 - 1 );
        }

        if ( ( mark.y_ - radiusCut_ ) < 0 )
        {
            intersection[ 4 ] = true;
            addTransfer( 13 - 1 );
        }
        else if ( ( mark.y_ + radiusCut_ ) > borders_.y_ )
        {
            intersection[ 2 ] = true;
            addTransfer( 15 - 1 );
        }

        if ( ( mark.z_ - radiusCut_ ) < 0 )
        {
            intersection[ 3 ] = true;
            addTransfer( 17 - 1 );
        }
        else if ( ( mark.z_ + radiusCut_ ) > borders_.z_ )
        {
            intersection[ 1 ] = true;
            addTransfer( 11 - 1 );
        }

        if ( intersection[ 0 ] && intersection[ 1 ] )
        {
            addTransfer( 2 - 1 );
        }
        if ( intersection[ 0 ] && intersection[ 2 ] )
        {
            addTransfer( 6 - 1 );
        }
        if ( intersection[ 0 ] && intersection[ 3 ] )
        {
            addTransfer( 8 - 1 );
        }
        if ( intersection[ 0 ] && intersection[ 4 ] )
        {
            addTransfer( 4 - 1 );
        }
        //--
        if ( intersection[ 1 ] && intersection[ 4 ] )
        {
            addTransfer( 10 - 1 );
        }
        if ( intersection[ 1 ] && intersection[ 2 ] )
        {
            addTransfer( 12 - 1 );
        }
        //--
        if ( intersection[ 3 ] && intersection[ 2 ] )
        {
            addTransfer( 18 - 1 );
        }
        if ( intersection[ 3 ] && intersection[ 4 ] )
        {
            addTransfer( 16 - 1 );
        }
        //--
        if ( intersection[ 5 ] && intersection[ 1 ] )
        {
            addTransfer( 20 - 1 );
        }
        if ( intersection[ 5 ] && intersection[ 2 ] )
        {
            addTransfer( 24 - 1 );
        }
        if ( intersection[ 5 ] && intersection[ 3 ] )
        {
            addTransfer( 26 - 1 );
        }
        if ( intersection[ 5 ] && intersection[ 4 ] )
        {
            addTransfer( 22 - 1 );
        }
        //-----
        if ( intersection[ 0 ] && intersection[ 1 ] && intersection[ 4 ] )
        {
            addTransfer( 1 - 1 );
        }
        if ( intersection[ 0 ] && intersection[ 1 ] && intersection[ 2 ] )
        {
            addTransfer( 3 - 1 );
        }
        if ( intersection[ 0 ] && intersection[ 2 ] && intersection[ 3 ] )
        {
            addTransfer( 9 - 1 );
        }
        if ( intersection[ 0 ] && intersection[ 3 ] && intersection[ 4 ] )
        {
            addTransfer( 7 - 1 );
        }
        //--
        if ( intersection[ 5 ] && intersection[ 1 ] && intersection[ 4 ] )
        {
            addTransfer( 19 - 1 );
        }
        if ( intersection[ 5 ] && intersection[ 1 ] && intersection[ 2 ] )
        {
            addTransfer( 21 - 1 );
        }
        if ( intersection[ 5 ] && intersection[ 2 ] && intersection[ 3 ] )
        {
            addTransfer( 27 - 1 );
        }
        if ( intersection[ 0 ] && intersection[ 3 ] && intersection[ 4 ] )
        {
            addTransfer( 25 - 1 );
        }

        addTransfer( 14 - 1 );

        Vector transferMark = mark;
        for ( int i = 0; i < transferQuantity; ++i )
        {
            transferMark = mark + transferNum[ i ];
            if ( ( coordinate - transferMark ).getModule() < radiusCut_ )
            {
                result += field->psyField( mark, particle );
            }
        }
    }

    return result;
}

void CyclicBoundedField::setBorders( const Vector& borders )
{
    borders_ = borders;
}

const Vector& CyclicBoundedField::getBorders() const
{
    return borders_;
}

void CyclicBoundedField::setRadiusCut( double radiusCut )
{
    radiusCut_ = radiusCut;
}

double CyclicBoundedField::getRadiusCut() const
{
    return radiusCut_;
}

void CyclicBoundedField::addTransfer( int num )
{
    transferNum[ transferQuantity ] = num;
    ++transferQuantity;
}

} // namespace phycoub
