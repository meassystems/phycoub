/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-16 00:56:45
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-16 00:58:12
 */

#pragma once

namespace phycoub
{

struct ParticleOptions final
{
    ParticleOptions() = default;
    ParticleOptions( double m, double q );

    double m_ = 0.;
    double q_ = 0.;
};

} // namespace phycoub