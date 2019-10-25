/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 16:20:27
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-26 00:14:13
 */

#pragma once

#include <vector>
#include <list>
#include <cstdint>

#include "Particle.h"

namespace phycoub
{

class ParticleGroup final : public std::vector< ParticlePtr >
{
  public:
    ParticleGroup() = default;
    ~ParticleGroup() = default;
};

using ParticleGroupPtr = std::shared_ptr< ParticleGroup >;

class ParticleGroupList final : public std::list< ParticleGroupPtr >
{
  private:
    using ParticleGroupContainerType = std::list< ParticleGroupPtr >;

  public:
    ParticleGroupList() = default;
    ~ParticleGroupList() = default;

    class ConstIterator
    {
      public:
        // Implementation of std::iterator
        using iterator_category = std::forward_iterator_tag;
        using value_typ = ParticlePtr;
        using difference_type = int;
        using pointer = const ParticlePtr*;
        using reference = const ParticlePtr&;

        ConstIterator(
            std::shared_ptr< ParticleGroupContainerType::const_iterator > groupIterator,
            std::shared_ptr< ParticleGroupContainerType::const_iterator >
                groupIteratorEnd,
            std::shared_ptr< ParticleGroup::const_iterator > particleIterator );
        ~ConstIterator() = default;

        ConstIterator& operator++();
        ConstIterator operator++( int );

        const reference operator*();
        const pointer operator->();

        bool operator==( const ConstIterator& another );
        bool operator!=( const ConstIterator& another );

      private:
        std::shared_ptr< ParticleGroupContainerType::const_iterator > groupIterator_;
        std::shared_ptr< ParticleGroupContainerType::const_iterator > groupIteratorEnd_;
        std::shared_ptr< ParticleGroup::const_iterator > particleIterator_;
    };

    class Iterator
    {
      public:
        // Implementation of std::iterator
        using iterator_category = std::forward_iterator_tag;
        using value_typ = ParticlePtr;
        using difference_type = int;
        using pointer = ParticlePtr*;
        using reference = ParticlePtr&;

        explicit Iterator(
            std::shared_ptr< ParticleGroupContainerType::iterator > groupIterator,
            std::shared_ptr< ParticleGroupContainerType::iterator > groupIteratorEnd,
            std::shared_ptr< ParticleGroup::iterator > particleIterator );
        ~Iterator() = default;

        Iterator& operator++();
        Iterator operator++( int );

        reference operator*();
        pointer operator->();

        bool operator==( const Iterator& another );
        bool operator!=( const Iterator& another );

      private:
        std::shared_ptr< ParticleGroupContainerType::iterator > groupIterator_;
        std::shared_ptr< ParticleGroupContainerType::iterator > groupIteratorEnd_;
        std::shared_ptr< ParticleGroup::iterator > particleIterator_;
    };

    ConstIterator cbegin() const;
    ConstIterator cend() const;

    Iterator begin();
    Iterator end();

    size_t getParticleCount() const;
};

} // namespace phycoub