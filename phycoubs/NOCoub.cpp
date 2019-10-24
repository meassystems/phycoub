/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-19 19:07:08
 * @Last Modified by:   Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-19 19:07:08
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
{
    createField_.reserve( 4 );
    feelField_.reserve( 4 );
    srand( time( NULL ) );
    rand();
    rand();
    rand();
    // NN
    createField_.push_back(
        CreateField( &azotField_, &cyclicBoundedFieldN_, "LD NN Field" ) );
    feelField_.push_back(
        FeelField( &createField_.back(), &azotInterworking, "LD NN Feel" ) );
    /*for(int i = 0; i < 100; i++) {
            azot_.push_back(new Particle(Vector((rand()/(double)RAND_MAX)*borders_.x_,
    (rand()/(double)RAND_MAX)*borders_.y_, (rand()/(double)RAND_MAX)*borders_.z_),
    Vector(.0, .0, .0), mN_, z_, &cyclicBorder_));
    }*/
    azot_.push_back(
        new Particle( Vector( 0.5 * borders_.x_, 0.5 * borders_.y_, 0.45 * borders_.z_ ),
            Vector( .0, .0, .0 ), mN_, z_, &cyclicBorder_ ) );
    createField_.back().addGroupParticle( azot_ );
    feelField_.back().addGroupParticle( azot_ );
    // OO
    createField_.push_back(
        CreateField( &oxygenField_, &cyclicBoundedFieldO_, "LD OO Field" ) );
    feelField_.push_back(
        FeelField( &createField_.back(), &oxygenInterworking, "LD OO Feel" ) );
    /*for(int i = 0; i < 100; i++) {
            oxygen_.push_back(new Particle(Vector((rand()/(double)RAND_MAX)*borders_.x_,
    (rand()/(double)RAND_MAX)*borders_.y_, (rand()/(double)RAND_MAX)*borders_.z_),
    Vector(.0, .0, .0), mO_, z_, &cyclicBorder_));
    }*/
    oxygen_.push_back(
        new Particle( Vector( 0.5 * borders_.x_, 0.5 * borders_.y_, 0.55 * borders_.z_ ),
            Vector( .0, .0, .0 ), mO_, z_, &cyclicBorder_ ) );
    createField_.back().addGroupParticle( oxygen_ );
    feelField_.back().addGroupParticle( oxygen_ );
    // NO
    createField_.push_back(
        CreateField( &NOField_, &cyclicBoundedFieldNO_, "LD NO Field" ) );
    feelField_.push_back(
        FeelField( &createField_.back(), &NOInterworking, "LD OO Feel" ) );
    createField_.back().addGroupParticle( azot_ );
    feelField_.back().addGroupParticle( oxygen_ );
    // ON
    createField_.push_back(
        CreateField( &NOField_, &cyclicBoundedFieldNO_, "LD NO Field" ) );
    feelField_.push_back(
        FeelField( &createField_.back(), &NOInterworking, "LD OO Feel" ) );
    createField_.back().addGroupParticle( oxygen_ );
    feelField_.back().addGroupParticle( azot_ );

    groupLeapFrog_.push_back( CalculationGroup( &leapFrog, &dt_ ) );
    groupLeapFrog_.back().addGroupParticle( azot_ );
    groupLeapFrog_.back().addGroupParticle( oxygen_ );
}
NOCoub::~NOCoub()
{
}

void NOCoub::phyCoub()
{

    for_each( feelField_.begin(), feelField_.end(),
        []( FeelField &feelField_ ) { feelField_.phyCalcInterworking(); } );
    for_each( groupLeapFrog_.begin(), groupLeapFrog_.end(),
        []( CalculationGroup &groupLeapFrog_ ) { groupLeapFrog_.phyModeling(); } );
}

} /* namespace phycoub */
