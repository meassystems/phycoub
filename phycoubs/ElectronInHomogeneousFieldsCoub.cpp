/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 11:55:14
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 13:02:11
 */

#include "ElectronInHomogeneousFieldsCoub.h"

#include "FeelField.h"

namespace phycoub
{

ElectronInHomogeneousFieldsCoub::ElectronInHomogeneousFieldsCoub()
{
    fieldResponsive_.push_back( feelWithCulonInterworking_ );
    calculationGroup_.push_back( leapFrogCalculationGroup_ );
}

void ElectronInHomogeneousFieldsCoub::phyCoub()
{
}

} // namespace phycoub