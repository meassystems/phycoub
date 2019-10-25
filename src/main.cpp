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
    /*
    try
    {
        NOCoub NOPhyCoub;
        while ( true )
        {
            NOPhyCoub.phyCoub();
            std::cout << NOPhyCoub.azot_->front()->coordinate_.x_ << " ; "
                      << NOPhyCoub.azot_->front()->coordinate_.y_ << " ; "
                      << NOPhyCoub.azot_->front()->coordinate_.z_;
            std::cout << "	-	" << NOPhyCoub.azot_->back()->coordinate_.x_
                      << " ; " << NOPhyCoub.azot_->back()->coordinate_.y_ << " ; "
                      << NOPhyCoub.azot_->back()->coordinate_.z_ << std::endl;
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
             ArCoub ArCoub;
             while ( true )
             {
                 ArCoub.phyCoub();
                 std::cout << ArCoub.argon_->front()->coordinate_.x_ << " ; "
                           << ArCoub.argon_->front()->coordinate_.y_ << " ; "
                           << ArCoub.argon_->front()->coordinate_.z_;
                 std::cout << "	-	" << ArCoub.argon_->back()->coordinate_.x_
                           << " ; " << ArCoub.argon_->back()->coordinate_.y_ << " ; "
                           << ArCoub.argon_->back()->coordinate_.z_ << std::endl;
             }
         }
         catch ( char const* str )
         {
             std::cout << str;
         }
     */

    try
    {
        FigureDemonstration figureDemonstration;
        while ( true )
        {
            figureDemonstration.phyCoub();
            std::cout << figureDemonstration.lineN.particles_->front()->coordinate_.x_
                      << " ; "
                      << figureDemonstration.lineN.particles_->front()->coordinate_.y_
                      << " ; "
                      << figureDemonstration.lineN.particles_->front()->coordinate_.z_;
            std::cout << "	-	"
                      << figureDemonstration.lineN.particles_->back()->coordinate_.x_
                      << " ; "
                      << figureDemonstration.lineN.particles_->back()->coordinate_.y_
                      << " ; "
                      << figureDemonstration.lineN.particles_->back()->coordinate_.z_
                      << std::endl;
        }
    }
    catch ( char const* str )
    {
        std::cout << str;
    }

    return 0;
}
