/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-16 02:16:59
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-16 02:25:09
 */

#include "LifeTimeControllerBase.h"

#include "ProgrammingException.h"

namespace phycoub
{

LifeTimeControllerBase::LifeTimeControllerBase( ParticleSourcePtr particleSource )
    : particleSource_( particleSource )
{
}

void LifeTimeControllerBase::setParticleGroup( ParticleGroupPtr particleGroup )
{
    PROGRAMMING_ASSERT( particleGroup );
    addParticleGroup( particleGroup );
}

void LifeTimeControllerBase::setParticleSource( ParticleSourcePtr particlesource )
{
    PROGRAMMING_ASSERT( particlesource );
    particleSource_ = particlesource;
}

ParticleSourcePtr LifeTimeControllerBase::getParticleSource() const
{
    return particleSource_;
}

} // namespace phycoub