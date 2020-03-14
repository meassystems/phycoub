/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-14 09:23:49
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-14 16:01:01
 */

#pragma once

#include <string>
#include <list>
#include <memory>

namespace phycoub
{

class Utils final
{
  public:
    Utils() = delete;

    template< typename... Args >
    static std::string formatString( const std::string& format, Args... args );

    template< typename ObserverType >
    static void removeReleasedPtrsListOfWeakPtr(
        std::list< std::weak_ptr< ObserverType > >* list );

    template< typename ObserverType, typename Function >
    static void callForObserversAndRemoveReleasedPtrs(
        std::list< std::weak_ptr< ObserverType > >* observers, Function function );
};

template< typename... Args >
std::string Utils::formatString( const std::string& format, Args... args )
{
    // todo std::format in C++20
    std::string formatedString;
    formatedString.resize( 500 );
    size_t length = snprintf( const_cast< char* >( formatedString.data() ),
        formatedString.length(), format.data(), args... );
    formatedString.resize( length );

    return formatedString;
}

template< typename ObserverType >
void Utils::removeReleasedPtrsListOfWeakPtr(
    std::list< std::weak_ptr< ObserverType > >* list )
{
    using IteratorType = typename std::list< std::weak_ptr< ObserverType > >::iterator;
    for ( IteratorType iterator = list->begin(); iterator != list->end(); ++iterator )
    {
        if ( iterator->expired() )
        {
            list->erase( iterator );
        }
    }
}

template< typename ObserverType, typename Function >
void Utils::callForObserversAndRemoveReleasedPtrs(
    std::list< std::weak_ptr< ObserverType > >* observers, Function function )
{
    bool hasReleasedObserver = false;
    for ( auto observerWeak : *observers )
    {
        if ( auto observer = observerWeak.lock() )
        {
            function( observer );
        }
        else
        {
            hasReleasedObserver = true;
        }
    }

    if ( hasReleasedObserver )
    {
        removeReleasedPtrsListOfWeakPtr( observers );
    }
}

} // namespace phycoub