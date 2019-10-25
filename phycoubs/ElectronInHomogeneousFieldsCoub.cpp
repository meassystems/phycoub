/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 11:55:14
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 13:57:50
 */

#include "ElectronInHomogeneousFieldsCoub.h"

#include "FeelField.h"

namespace phycoub
{

ElectronInHomogeneousFieldsCoub::ElectronInHomogeneousFieldsCoub()
    : PhyCoub( dt_ )
{
    addFieldResponsive( feelWithCulonInterworking_ );
    addCalculationGroup( leapFrogCalculationGroup_ );
}

} // namespace phycoub