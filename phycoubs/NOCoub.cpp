/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-19 19:07:08
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-06 00:04:26
 */

#include <NOCoub.h >

#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <time.h>

namespace phycoub
{

NOCoub::NOCoub()
{
    setDeltaTime( dt_ );

    srand( time( NULL ) );
    rand();
    rand();
    rand();
    // NN
    azot_->emplace_back( std::make_shared< Particle >(
        Vector( 0.5 * borders_.x_, 0.5 * borders_.y_, 0.45 * borders_.z_ ),
        Vector( .0, .0, .0 ), mN_, z_ ) );
    azot2azotFieldCreator_->addParticleGroup( azot_ );
    azot2azotFieldResponsive_->addParticleGroup( azot_ );
    addFieldResponsive( azot2azotFieldResponsive_ );
    // OO
    oxygen_->emplace_back( std::make_shared< Particle >(
        Vector( 0.5 * borders_.x_, 0.5 * borders_.y_, 0.55 * borders_.z_ ),
        Vector( .0, .0, .0 ), mO_, z_ ) );
    oxygen2oxygenFieldCreator_->addParticleGroup( oxygen_ );
    oxygen2oxyhenFieldResponsive_->addParticleGroup( oxygen_ );
    addFieldResponsive( oxygen2oxyhenFieldResponsive_ );

    azot2oxygenInterCommunication_->addParticleGroup( azot_ );
    azot2oxygenInterCommunication_->addParticleGroup( oxygen_ );
    addFieldResponsive( azot2oxygenInterCommunication_ );

    leapFrogCalculationGroup_->addParticleGroup( azot_ );
    leapFrogCalculationGroup_->addParticleGroup( oxygen_ );
    addCalculationGroup( leapFrogCalculationGroup_ );
}

} // namespace phycoub
