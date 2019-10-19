/*
 * FigureDemonstration.cpp
 *
 *  Created on: Dec 22, 2016
 *      Author: root
 */

#include <FigureDemonstration.h>

#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <time.h>

namespace phycoub
{

FigureDemonstration::FigureDemonstration()
{
    srand( time( NULL ) );
    rand();
    rand();
    rand();
}
FigureDemonstration::~FigureDemonstration()
{
}

void FigureDemonstration::phyCoub()
{
    /*for_each(feelField_.begin(), feelField_.end(), [](FeelField& feelField_) {

    }
    );*/
}

} /* namespace phycoub */
