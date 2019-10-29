/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 16:20:27
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-29 14:16:32
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

    using GroupConstIterator = ParticleGroupContainerType::const_iterator;
    using GroupIterator = ParticleGroupContainerType::iterator;

    GroupConstIterator beginGroup() const;
    GroupConstIterator endGroup() const;

    GroupIterator beginGroup();
    GroupIterator endGroup();

    class ParticleConstIterator
    {
      public:
        // Implementation of std::iterator
        using iterator_category = std::forward_iterator_tag;
        using value_typ = ParticlePtr;
        using difference_type = int;
        using pointer = const ParticlePtr*;
        using reference = const ParticlePtr&;

        ParticleConstIterator( std::shared_ptr< GroupConstIterator > groupIterator,
            std::shared_ptr< GroupConstIterator > groupIteratorEnd,
            std::shared_ptr< ParticleGroup::const_iterator > particleIterator );
        ~ParticleConstIterator() = default;

        ParticleConstIterator& operator++();
        ParticleConstIterator operator++( int );

        const reference operator*();
        const pointer operator->();

        bool operator==( const ParticleConstIterator& another );
        bool operator!=( const ParticleConstIterator& another );

      private:
        std::shared_ptr< GroupConstIterator > groupIterator_;
        std::shared_ptr< GroupConstIterator > groupIteratorEnd_;
        std::shared_ptr< ParticleGroup::const_iterator > particleIterator_;
    };

    class ParticleIterator
    {
      public:
        // Implementation of std::iterator
        using iterator_category = std::forward_iterator_tag;
        using value_typ = ParticlePtr;
        using difference_type = int;
        using pointer = ParticlePtr*;
        using reference = ParticlePtr&;

        explicit ParticleIterator( std::shared_ptr< GroupIterator > groupIterator,
            std::shared_ptr< GroupIterator > groupIteratorEnd,
            std::shared_ptr< ParticleGroup::iterator > particleIterator );
        ~ParticleIterator() = default;

        ParticleIterator& operator++();
        ParticleIterator operator++( int );

        reference operator*();
        pointer operator->();

        bool operator==( const ParticleIterator& another );
        bool operator!=( const ParticleIterator& another );

      private:
        std::shared_ptr< GroupIterator > groupIterator_;
        std::shared_ptr< GroupIterator > groupIteratorEnd_;
        std::shared_ptr< ParticleGroup::iterator > particleIterator_;
    };

    ParticleConstIterator begin() const;
    ParticleConstIterator end() const;

    ParticleIterator begin();
    ParticleIterator end();

    size_t getParticleCount() const;
};

} // namespace phycoub