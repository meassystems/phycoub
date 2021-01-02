/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-11-05 23:02:39
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-14 16:46:02
 */

#pragma once

#include <stdint.h>

namespace phycoub
{

using IDType = uint64_t;
/*
 * Базовый класс для именуемых сущностей
 */
class HasId
{
  public:
    HasId();
    virtual ~HasId() = default;

    IDType getId() const;

  private:
    static IDType idUniquer;
    IDType id = 0;
};

} // namespace phycoub