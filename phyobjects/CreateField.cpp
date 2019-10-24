/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-23 22:09:38
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-24 20:25:00
 */

#include <CreateField.h>

#include <iterator>
#include <algorithm>

#include "BorderFieldCondition.h"

namespace phycoub
{

CreateField::CreateField( FieldFunction* functionField,
    BorderFieldCondition* borderFieldCondition, const std::string& fieldName )
    : CreateFieldBase( fieldName )
    , particles_( 0 )
    , functionField_( functionField )
    , borderFieldCondition_( borderFieldCondition )
{
}

Vector CreateField::getFieldInMark( const Vector& mark )
{
    Vector result;

    for_each( particles_.begin(), particles_.end(), [&]( const Particle* source ) {
        result += borderFieldCondition_->phyFieldWithBorderCondition(
            functionField_, *source, mark );
    } );

    return result;
}

void CreateField::addParticle( Particle* particle )
{
    particles_.push_back( particle );
}
void CreateField::addGroupParticle( std::vector< Particle* >& particles )
{
    for_each( particles.begin(), particles.end(),
        [&]( Particle* particle ) { particles_.push_back( particle ); } );
}
void CreateField::removeParticle( Particle* particle )
{
    std::vector< Particle* >::iterator itr = particles_.begin();
    while ( itr != particles_.end() )
    {
        if ( ( *itr )->index == particle->index )
        {
            particles_.erase( itr );
            break;
        }
        ++itr;
    }
}

} /* namespace phycoub */
