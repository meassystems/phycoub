/*
 * main.cpp
 *
 *  Created on: Oct 13, 2016
 *      Author: root
 */

#include <iostream>
#include <string>

#include "NOCoub.h"
#include "ArCoub.h"
#include "FigureDemonstration.h"

using namespace phycoub;

int main()
{

    std::cout.precision( 17 );
    try
    {
        NOCoub NOPhyCoub;
        while ( true )
        {
            NOPhyCoub.phyCoub();
            std::cout << NOPhyCoub.azot_->front()->getCoordinate().z_
                    - NOPhyCoub.oxygen_->front()->getCoordinate().z_
                      << " ; " << NOPhyCoub.azot_->front()->getSpeed().z_ << std::endl;
        }
    }
    catch ( char const* str )
    {
        std::cout << str;
    }
    /*
    try
    {
        ArCoub ArCoub;
        while ( true )
        {
            ArCoub.phyCoub();
            std::cout << ArCoub.argon_->front()->getCoordinate().x_ << " ; "
                      << ArCoub.argon_->front()->getCoordinate().y_ << " ; "
                      << ArCoub.argon_->front()->getCoordinate().z_;
            std::cout << "	-	" << ArCoub.argon_->back()->getCoordinate().x_
                      << " ; " << ArCoub.argon_->back()->getCoordinate().y_ << " ; "
                      << ArCoub.argon_->back()->getCoordinate().z_ << std::endl;
        }
    }
    catch ( char const* str )
    {
        std::cout << str;
    }
    */
    /*
        try
        {
            FigureDemonstration figureDemonstration;
            while ( true )
            {
                figureDemonstration.phyCoub();
                std::cout <<
       figureDemonstration.lineN.particles_->front()->getCoordinate().x_
                          << " ; "
                          <<
       figureDemonstration.lineN.particles_->front()->getCoordinate().y_
                          << " ; "
                          <<
       figureDemonstration.lineN.particles_->front()->getCoordinate().z_; std::cout << "
       -
       "
                          <<
       figureDemonstration.lineN.particles_->back()->getCoordinate().x_
                          << " ; "
                          <<
       figureDemonstration.lineN.particles_->back()->getCoordinate().y_
                          << " ; "
                          <<
       figureDemonstration.lineN.particles_->back()->getCoordinate().z_
                          << std::endl;
            }
        }
        catch ( char const* str )
        {
            std::cout << str;
        }
    */
    return 0;
}
