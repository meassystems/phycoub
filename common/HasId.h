/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-11-05 23:02:39
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-06 14:52:42
 */

#pragma once

namespace phycoub
{

using IDType = long;

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