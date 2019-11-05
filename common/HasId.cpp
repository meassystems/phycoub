/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-11-05 23:05:43
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-05 23:15:10
 */

#include "HasId.h"

namespace phycoub
{

long HasId::idUniquer = 0;

HasId::HasId()
    : id( idUniquer++ )
{
}

IDType HasId::getId() const
{
    return id;
}

} // namespace phycoub