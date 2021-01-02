/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-11-05 23:05:43
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-14 16:47:22
 */

#include "HasId.h"

namespace phycoub
{

IDType HasId::idUniquer = 0;

HasId::HasId()
    : id( idUniquer++ )
{
}

IDType HasId::getId() const
{
    return id;
}

} // namespace phycoub