/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-11-05 23:02:39
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-11-05 23:15:05
 */

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