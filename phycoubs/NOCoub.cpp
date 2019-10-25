/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-19 19:07:08
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 14:46:32
 */

#include <NOCoub.h >

#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "temperatureControl.h"

namespace phycoub
{

NOCoub::NOCoub()
    : PhyCoub( dt_ )
{
    srand( time( NULL ) );
    rand();
    rand();
    rand();
    // NN
    azot_.push_back(
        new Particle( Vector( 0.5 * borders_.x_, 0.5 * borders_.y_, 0.45 * borders_.z_ ),
            Vector( .0, .0, .0 ), mN_, z_, &cyclicBorder_ ) );
    azot2azotFieldCreator_->addGroupParticle( azot_ );
    azot2azotFieldResponsive_->addGroupParticle( azot_ );
    addFieldResponsive( azot2azotFieldResponsive_ );
    // OO
    oxygen_.push_back(
        new Particle( Vector( 0.5 * borders_.x_, 0.5 * borders_.y_, 0.55 * borders_.z_ ),
            Vector( .0, .0, .0 ), mO_, z_, &cyclicBorder_ ) );
    oxygen2oxygenFieldCreator_->addGroupParticle( oxygen_ );
    oxygen2oxyhenFieldResponsive_->addGroupParticle( oxygen_ );
    addFieldResponsive( oxygen2oxyhenFieldResponsive_ );
    // NO
    azot2oxygenFieldCreator_->addGroupParticle( azot_ );
    azot2oxygenFieldResponsive_->addGroupParticle( oxygen_ );
    addFieldResponsive( azot2oxygenFieldResponsive_ );
    // ON
    oxygen2azotFieldCreator_->addGroupParticle( oxygen_ );
    oxygen2azotFieldResponsive_->addGroupParticle( azot_ );
    addFieldResponsive( oxygen2azotFieldResponsive_ );

    leapFrogCalculationGroup_->addGroupParticle( azot_ );
    leapFrogCalculationGroup_->addGroupParticle( oxygen_ );
    addCalculationGroup( leapFrogCalculationGroup_ );
}

} /* namespace phycoub */
