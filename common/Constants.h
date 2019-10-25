/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 12:33:52
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-25 12:11:39
 */

namespace phycoub
{

struct ElectricConstants final
{
    ElectricConstants() = delete;

    constexpr static double epselon0 = 8.8541878128131313e-12;
    constexpr static double electronWeight = 9.109383561111111e-31;
    constexpr static double electronCharge = -1.602176620898989e-19;
};

} // namespace phycoub