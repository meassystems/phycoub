/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 16:32:05
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-31 16:23:33
 */

#include "ParticleGroup.h"

#include <algorithm>

namespace phycoub
{

void ParticleGroup::remove( long index )
{

    for ( iterator particleIterator = begin(); particleIterator != end();
          ++particleIterator )
    {
        if ( ( *particleIterator )->getIndex() == index )
        {
            erase( particleIterator );
            return;
        }
    }
}

void ParticleGroupList::removeParticle( long index )
{
    for ( ParticleIterator particleIterator = begin(); particleIterator != end();
          ++particleIterator )
    {
        if ( ( *particleIterator )->getIndex() == index )
        {
            GroupIterator groupIterator = particleIterator.getGropIterator();
            ( *groupIterator )->remove( index );
            return;
        }
    }
}

ParticleGroupList::GroupConstIterator ParticleGroupList::beginGroup() const
{
    return ParticleGroupList::ParticleGroupContainerType::begin();
}

ParticleGroupList::GroupConstIterator ParticleGroupList::endGroup() const
{
    return ParticleGroupList::ParticleGroupContainerType::end();
}

ParticleGroupList::GroupIterator ParticleGroupList::beginGroup()
{
    return ParticleGroupList::ParticleGroupContainerType::begin();
}

ParticleGroupList::GroupIterator ParticleGroupList::endGroup()
{
    return ParticleGroupList::ParticleGroupContainerType::end();
}

ParticleGroupList::ParticleConstIterator ParticleGroupList::begin() const
{
    if ( getParticleCount() == 0 )
    {
        return ParticleConstIterator{ nullptr, nullptr, nullptr };
    }

    auto groupBeginIterator = ParticleGroupContainerType::cbegin();
    return ParticleConstIterator{ std::make_shared< GroupConstIterator >(
                                      groupBeginIterator ),
        std::make_shared< GroupConstIterator >( ParticleGroupContainerType::cend() ),
        std::make_shared< ParticleGroup::const_iterator >(
            ( *groupBeginIterator )->cbegin() ) };
}

ParticleGroupList::ParticleConstIterator ParticleGroupList::end() const
{
    if ( getParticleCount() == 0 )
    {
        return ParticleConstIterator{ nullptr, nullptr, nullptr };
    }

    GroupConstIterator endGroupIterator = ParticleGroupContainerType::cend();
    GroupConstIterator lastGroupIterator = --ParticleGroupContainerType::cend();
    ParticleGroup::const_iterator endParticleIterator = ( *lastGroupIterator )->cend();

    return ParticleConstIterator{ std::make_shared< GroupConstIterator >(
                                      endGroupIterator ),
        std::make_shared< GroupConstIterator >( endGroupIterator ),
        std::make_shared< ParticleGroup::const_iterator >( endParticleIterator ) };
}

ParticleGroupList::ParticleIterator ParticleGroupList::begin()
{
    if ( getParticleCount() == 0 )
    {
        return ParticleIterator{ nullptr, nullptr, nullptr };
    }

    auto groupBeginIterator = ParticleGroupContainerType::begin();
    return ParticleIterator{ std::make_shared< GroupIterator >( groupBeginIterator ),
        std::make_shared< GroupIterator >( ParticleGroupContainerType::end() ),
        std::make_shared< ParticleGroup::iterator >( ( *groupBeginIterator )->begin() ) };
}

ParticleGroupList::ParticleIterator ParticleGroupList::end()
{
    if ( getParticleCount() == 0 )
    {
        return ParticleIterator{ nullptr, nullptr, nullptr };
    }

    GroupIterator endGroupIterator = ParticleGroupContainerType::end();
    GroupIterator lastGroupIterator = --ParticleGroupContainerType::end();
    ParticleGroup::iterator endParticleIterator = ( *lastGroupIterator )->end();

    return ParticleIterator{ std::make_shared< GroupIterator >( endGroupIterator ),
        std::make_shared< GroupIterator >( endGroupIterator ),
        std::make_shared< ParticleGroup::iterator >( endParticleIterator ) };
}

size_t ParticleGroupList::getParticleCount() const
{
    size_t particleCount = 0;
    std::for_each( ParticleGroupContainerType::cbegin(),
        ParticleGroupContainerType::cend(),
        [&particleCount]( ParticleGroupPtr particleGroup ) {
            particleCount += particleGroup->size();
        } );
    return particleCount;
}

ParticleGroupList::ParticleConstIterator::ParticleConstIterator(
    std::shared_ptr< GroupConstIterator > groupIterator,
    std::shared_ptr< GroupConstIterator > groupIteratorEnd,
    std::shared_ptr< ParticleGroup::const_iterator > particleIterator )
{
    groupIterator_ = groupIterator;
    groupIteratorEnd_ = groupIteratorEnd;
    particleIterator_ = particleIterator;
}

ParticleGroupList::ParticleConstIterator& ParticleGroupList::ParticleConstIterator::
operator++()
{
    ++*particleIterator_;
    if ( *particleIterator_ == ( **groupIterator_ )->cend() )
    {
        ++*groupIterator_;
        if ( *groupIterator_ != *groupIteratorEnd_ )
        {
            *particleIterator_ = ( **groupIterator_ )->cbegin();
        }
    }

    return *this;
}

ParticleGroupList::ParticleConstIterator ParticleGroupList::ParticleConstIterator::
operator++( int )
{
    ParticleConstIterator current = *this;

    ++*particleIterator_;
    if ( *particleIterator_ == ( **groupIterator_ )->cend() )
    {
        ++*groupIterator_;
        if ( *groupIterator_ != *groupIteratorEnd_ )
        {
            *particleIterator_ = ( **groupIterator_ )->cbegin();
        }
    }

    return current;
}

const ParticleGroupList::ParticleConstIterator::reference
    ParticleGroupList::ParticleConstIterator::operator*()
{
    return **particleIterator_;
}

const ParticleGroupList::ParticleConstIterator::pointer
    ParticleGroupList::ParticleConstIterator::operator->()
{
    return &**particleIterator_;
}

bool ParticleGroupList::ParticleConstIterator::operator==(
    const ParticleConstIterator& another )
{
    if ( groupIterator_ == nullptr )
    {
        return another.groupIterator_ == nullptr;
    }

    return *groupIterator_ == *another.groupIterator_
        && *groupIteratorEnd_ == *another.groupIteratorEnd_
        && *particleIterator_ == *another.particleIterator_;
}

bool ParticleGroupList::ParticleConstIterator::operator!=(
    const ParticleConstIterator& another )
{
    return !operator==( another );
}

ParticleGroupList::GroupConstIterator
ParticleGroupList::ParticleConstIterator::getGropIterator()
{
    return *groupIterator_;
}

ParticleGroupList::ParticleIterator::ParticleIterator(
    std::shared_ptr< GroupIterator > groupIterator,
    std::shared_ptr< GroupIterator > groupIteratorEnd,
    std::shared_ptr< ParticleGroup::iterator > particleIterator )
{
    groupIterator_ = groupIterator;
    groupIteratorEnd_ = groupIteratorEnd;
    particleIterator_ = particleIterator;
}

ParticleGroupList::ParticleIterator& ParticleGroupList::ParticleIterator::operator++()
{
    ++*particleIterator_;
    if ( *particleIterator_ == ( **groupIterator_ )->end() )
    {
        ++*groupIterator_;
        if ( *groupIterator_ != *groupIteratorEnd_ )
        {
            *particleIterator_ = ( **groupIterator_ )->begin();
        }
    }

    return *this;
}

ParticleGroupList::ParticleIterator ParticleGroupList::ParticleIterator::operator++( int )
{
    ParticleIterator current = *this;

    ++*particleIterator_;
    if ( *particleIterator_ == ( **groupIterator_ )->end() )
    {
        ++*groupIterator_;
        if ( *groupIterator_ != *groupIteratorEnd_ )
        {
            *particleIterator_ = ( **groupIterator_ )->begin();
        }
    }

    return current;
}

ParticleGroupList::ParticleIterator::reference ParticleGroupList::ParticleIterator::
operator*()
{
    return **particleIterator_;
}

ParticleGroupList::ParticleIterator::pointer ParticleGroupList::ParticleIterator::
operator->()
{
    return &**particleIterator_;
}

bool ParticleGroupList::ParticleIterator::operator==( const ParticleIterator& another )
{
    if ( groupIterator_ == nullptr )
    {
        return another.groupIterator_ == nullptr;
    }

    return *groupIterator_ == *another.groupIterator_
        && *groupIteratorEnd_ == *another.groupIteratorEnd_
        && *particleIterator_ == *another.particleIterator_;
}

bool ParticleGroupList::ParticleIterator::operator!=( const ParticleIterator& another )
{
    return !operator==( another );
}

ParticleGroupList::GroupIterator ParticleGroupList::ParticleIterator::getGropIterator()
{
    return *groupIterator_;
}

} // namespace phycoub