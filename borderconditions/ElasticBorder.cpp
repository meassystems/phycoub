/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 18:10:42
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 09:00:28
 */

#include <ElasticBorder.h>
#include "Particle.h"

namespace phycoub
{

ElasticBorder::ElasticBorder( const Vector& borders )
    : BorderCondition( borders )
{
}

// virtual override
void ElasticBorder::psyMove(
    const Vector& move, const Vector& newSpeed, ParticlePtr* particle )
{
    Vector coordinate = ( *particle )->getCoordinate();
    IntersectionVector intersectionVector = getIntersectionVector( move, coordinate );

    if ( intersectionVector.intersection )
    {
        coordinate += move;
        ( *particle )->move( coordinate, newSpeed );
        return;
    }

    Vector move_ = move;
    do
    {
        coordinate = intersectionVector.intersectionMark;
        Vector elasticDirection(
            coordinate + move_ - intersectionVector.intersectionMark );

        switch ( intersectionVector.planeIntersection )
        {
            case 1:
                elasticDirection.x_ = -elasticDirection.x_;
                break;
            case 2:
                elasticDirection.y_ = -elasticDirection.y_;
                break;
            case 3:
                elasticDirection.z_ = -elasticDirection.z_;
                break;
            case 4:
                elasticDirection.x_ = -elasticDirection.x_;
                break;
            case 5:
                elasticDirection.y_ = -elasticDirection.y_;
                break;
            case 6:
                elasticDirection.z_ = -elasticDirection.z_;
                break;
        }
        move_ = elasticDirection;
        intersectionVector = getIntersectionVector( move_, coordinate );
    } while ( intersectionVector.intersection );
    coordinate += move;
    // todo: twice becose if once - invalid result for calculation models uses previes
    // values
    ( *particle )->move( coordinate, newSpeed );
    ( *particle )->move( coordinate, newSpeed );
}

const ElasticBorder::IntersectionVector ElasticBorder::getIntersectionVector(
    const Vector& move, const Vector& coordinate )
{
    IntersectionVector result_;
    PlaneMarket planeMarket_;
    Vector newCoordinate( coordinate + move );
    int lastIntersection = 0;

    result_.intersectionMark = coordinate + move;
    result_.intersection = !isMarkInBorder( result_.intersectionMark );
    if ( !result_.intersection )
    {
        return result_;
    }

    const Vector& borders = getBorders();
    while ( !isMarkInBorder( result_.intersectionMark ) )
    {
        if ( coordinate.x_ < 0. && lastIntersection != 1 )
        {
            lastIntersection = 1;
            planeMarket_.M1 = Vector( 0. );
            planeMarket_.M2 = Vector( 0., borders.y_, 0. );
            planeMarket_.M3 = Vector( 0., 0., borders.z_ );
        }
        else if ( coordinate.y_ < 0. && lastIntersection != 2 )
        {
            lastIntersection = 2;
            planeMarket_.M1 = Vector( 0. );
            planeMarket_.M2 = Vector( borders.x_, 0., 0. );
            planeMarket_.M3 = Vector( 0., 0., borders.z_ );
        }
        else if ( coordinate.z_ < 0. && lastIntersection != 3 )
        {
            lastIntersection = 3;
            planeMarket_.M1 = Vector( 0. );
            planeMarket_.M2 = Vector( borders.x_, 0., 0. );
            planeMarket_.M3 = Vector( 0., borders.y_, 0. );
        }
        else if ( coordinate.x_ > borders.x_ && lastIntersection != 4 )
        {
            lastIntersection = 4;
            planeMarket_.M1 = borders;
            planeMarket_.M2 = Vector( borders.x_, 0., borders.z_ );
            planeMarket_.M3 = Vector( borders.x_, borders.y_, 0. );
        }
        else if ( coordinate.y_ > borders.y_ && lastIntersection != 5 )
        {
            lastIntersection = 5;
            planeMarket_.M1 = borders;
            planeMarket_.M2 = Vector( 0., borders.y_, borders.z_ );
            planeMarket_.M3 = Vector( borders.x_, borders.y_, 0. );
        }
        else if ( coordinate.z_ > borders.z_ && lastIntersection != 6 )
        {
            lastIntersection = 6;
            planeMarket_.M1 = borders;
            planeMarket_.M2 = Vector( 0., borders.y_, borders.z_ );
            planeMarket_.M3 = Vector( borders.x_, 0., borders.z_ );
        }
        else
        {
            throw "Can't find intersection with board in "
                  "\"ElasticBorder::getPlaneMarket\"";
        }
        result_.intersectionMark = getMarkIntersection( planeMarket_, coordinate, move );
    }

    result_.planeIntersection = lastIntersection;
    return result_;
}

const Vector ElasticBorder::getMarkIntersection(
    const PlaneMarket& planeMarket, const Vector& mark, const Vector& direction )
{
    Vector result_;

    double A = ( planeMarket.M2.y_ - planeMarket.M1.y_ )
            * ( planeMarket.M3.z_ - planeMarket.M1.z_ )
        - ( planeMarket.M3.y_ - planeMarket.M1.y_ )
            * ( planeMarket.M2.z_ - planeMarket.M1.z_ );
    double B = ( planeMarket.M2.x_ - planeMarket.M1.x_ )
            * ( planeMarket.M3.z_ - planeMarket.M1.z_ )
        - ( planeMarket.M3.x_ - planeMarket.M1.x_ )
            * ( planeMarket.M2.z_ - planeMarket.M1.z_ );
    double C = ( planeMarket.M2.x_ - planeMarket.M1.x_ )
            * ( planeMarket.M3.y_ - planeMarket.M1.y_ )
        - ( planeMarket.M3.x_ - planeMarket.M1.x_ )
            * ( planeMarket.M2.y_ - planeMarket.M1.y_ );
    double D = A * ( -planeMarket.M1.x_ ) - B * ( -planeMarket.M1.y_ )
        - C * ( -planeMarket.M1.z_ );
    double zn_ = direction.x_ * A + direction.y_ * B + direction.z_ * C;

    if ( zn_ == 0. )
    {
        throw "Division by zero in \"ElasticBorder::getMarketIntersection\"";
    }

    double t = ( -D - A * mark.x_ - B * mark.y_ - C * mark.z_ ) / zn_;

    result_.x_ = direction.x_ * t + mark.x_;
    result_.y_ = direction.y_ * t + mark.y_;
    result_.z_ = direction.z_ * t + mark.z_;

    return result_;
}

bool ElasticBorder::isMarkInBorder( const Vector& mark )
{
    const Vector& borders = getBorders();
    if ( mark.x_ < 0 || mark.x_ > borders.x_ || mark.y_ < 0 || mark.y_ > borders.y_
        || mark.z_ < 0 || mark.z_ > borders.z_ )
    {
        return false;
    }
    return true;
}

} // namespace phycoub
