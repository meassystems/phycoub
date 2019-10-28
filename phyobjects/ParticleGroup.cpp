/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 16:32:05
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-28 16:24:42
 */

#include "ParticleGroup.h"

#include <algorithm>

namespace phycoub
{

ParticleGroupList::ConstIterator ParticleGroupList::begin() const
{
    if ( size() == 0 )
    {
        return ConstIterator{ nullptr, nullptr, nullptr };
    }

    auto groupBeginIterator = ParticleGroupContainerType::cbegin();
    return ConstIterator{ std::make_shared< ParticleGroupContainerType::const_iterator >(
                              groupBeginIterator ),
        std::make_shared< ParticleGroupContainerType::const_iterator >(
            ParticleGroupContainerType::cend() ),
        std::make_shared< ParticleGroup::const_iterator >(
            ( *groupBeginIterator )->cbegin() ) };
}

ParticleGroupList::ConstIterator ParticleGroupList::end() const
{
    if ( size() == 0 )
    {
        return ConstIterator{ nullptr, nullptr, nullptr };
    }

    ParticleGroupContainerType::const_iterator endGroupIterator
        = ParticleGroupContainerType::cend();
    ParticleGroupContainerType::const_iterator lastGroupIterator
        = --ParticleGroupContainerType::cend();
    ParticleGroup::const_iterator endParticleIterator = ( *lastGroupIterator )->cend();

    return ConstIterator{ std::make_shared< ParticleGroupContainerType::const_iterator >(
                              endGroupIterator ),
        std::make_shared< ParticleGroupContainerType::const_iterator >(
            endGroupIterator ),
        std::make_shared< ParticleGroup::const_iterator >( endParticleIterator ) };
}

ParticleGroupList::Iterator ParticleGroupList::begin()
{
    if ( size() == 0 )
    {
        return Iterator{ nullptr, nullptr, nullptr };
    }

    auto groupBeginIterator = ParticleGroupContainerType::begin();
    return Iterator{ std::make_shared< ParticleGroupContainerType::iterator >(
                         groupBeginIterator ),
        std::make_shared< ParticleGroupContainerType::iterator >(
            ParticleGroupContainerType::end() ),
        std::make_shared< ParticleGroup::iterator >( ( *groupBeginIterator )->begin() ) };
}

ParticleGroupList::Iterator ParticleGroupList::end()
{
    if ( size() == 0 )
    {
        return Iterator{ nullptr, nullptr, nullptr };
    }

    ParticleGroupContainerType::iterator endGroupIterator
        = ParticleGroupContainerType::end();
    ParticleGroupContainerType::iterator lastGroupIterator
        = --ParticleGroupContainerType::end();
    ParticleGroup::iterator endParticleIterator = ( *lastGroupIterator )->end();

    return Iterator{ std::make_shared< ParticleGroupContainerType::iterator >(
                         endGroupIterator ),
        std::make_shared< ParticleGroupContainerType::iterator >( endGroupIterator ),
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

ParticleGroupList::ConstIterator::ConstIterator(
    std::shared_ptr< ParticleGroupContainerType::const_iterator > groupIterator,
    std::shared_ptr< ParticleGroupContainerType::const_iterator > groupIteratorEnd,
    std::shared_ptr< ParticleGroup::const_iterator > particleIterator )
{
    groupIterator_ = groupIterator;
    groupIteratorEnd_ = groupIteratorEnd;
    particleIterator_ = particleIterator;
}

ParticleGroupList::ConstIterator& ParticleGroupList::ConstIterator::operator++()
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

ParticleGroupList::ConstIterator ParticleGroupList::ConstIterator::operator++( int )
{
    ConstIterator current = *this;

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

const ParticleGroupList::ConstIterator::reference ParticleGroupList::ConstIterator::
operator*()
{
    return **particleIterator_;
}

const ParticleGroupList::ConstIterator::pointer ParticleGroupList::ConstIterator::
operator->()
{
    return &**particleIterator_;
}

bool ParticleGroupList::ConstIterator::operator==( const ConstIterator& another )
{
    return *groupIterator_ == *another.groupIterator_
        && *groupIteratorEnd_ == *another.groupIteratorEnd_
        && *particleIterator_ == *another.particleIterator_;
}

bool ParticleGroupList::ConstIterator::operator!=( const ConstIterator& another )
{
    return !operator==( another );
}

ParticleGroupList::Iterator::Iterator(
    std::shared_ptr< ParticleGroupContainerType::iterator > groupIterator,
    std::shared_ptr< ParticleGroupContainerType::iterator > groupIteratorEnd,
    std::shared_ptr< ParticleGroup::iterator > particleIterator )
{
    groupIterator_ = groupIterator;
    groupIteratorEnd_ = groupIteratorEnd;
    particleIterator_ = particleIterator;
}

ParticleGroupList::Iterator& ParticleGroupList::Iterator::operator++()
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

ParticleGroupList::Iterator ParticleGroupList::Iterator::operator++( int )
{
    Iterator current = *this;

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

ParticleGroupList::Iterator::reference ParticleGroupList::Iterator::operator*()
{
    return **particleIterator_;
}

ParticleGroupList::Iterator::pointer ParticleGroupList::Iterator::operator->()
{
    return &**particleIterator_;
}

bool ParticleGroupList::Iterator::operator==( const Iterator& another )
{
    return *groupIterator_ == *another.groupIterator_
        && *groupIteratorEnd_ == *another.groupIteratorEnd_
        && *particleIterator_ == *another.particleIterator_;
}

bool ParticleGroupList::Iterator::operator!=( const Iterator& another )
{
    return !operator==( another );
}

} // namespace phycoub