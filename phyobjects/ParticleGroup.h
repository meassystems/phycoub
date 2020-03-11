/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 16:20:27
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 12:53:35
 */

#pragma once

#include <list>
#include <cstdint>

#include "Particle.h"

namespace phycoub
{

class ParticleGroup final
    : public std::list< ParticlePtr >
    , public HasId
{
  public:
    ParticleGroup() = default;
    ~ParticleGroup() = default;

    bool operator==( const ParticleGroup& particleGroup );

    bool remove( IDType id );
};

using ParticleGroupPtr = std::shared_ptr< ParticleGroup >;

class ParticleGroupList final : public std::list< ParticleGroupPtr >
{
  private:
    using ParticleGroupContainerType = std::list< ParticleGroupPtr >;

  public:
    ParticleGroupList() = default;
    ~ParticleGroupList() = default;

    ParticleGroupList deepCopy() const;

    void removeParticle( IDType id );
    void removeGroup( IDType id );

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

        GroupConstIterator getGropIterator();

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

        GroupIterator getGropIterator();

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