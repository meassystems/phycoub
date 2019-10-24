/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 18:53:11
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-23 19:13:26
 */

#include "FieldFunction.h"
#include "Vector.h"

namespace phycoub
{

class HomogeneousField : public FieldFunction
{
  public:
    explicit HomogeneousField( const Vector& direction );
    virtual ~HomogeneousField() = default;

    void setDirection( const Vector& direction );
    const Vector& getDirection() const;

  private:
    Vector direction_;
};

} // namespace phycoub