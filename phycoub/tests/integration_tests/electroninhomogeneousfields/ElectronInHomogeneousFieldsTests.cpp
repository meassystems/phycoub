#include "ElectronInHomogeneousFieldsTests.h"

#include <list>

#include "ElectronInHomogeneousFieldsCoub.h"
#include "ParticleOptionsCatalog.h"

using namespace phycoub;

TEST_F( ElectronInHomogeneousFieldsTests, ElectronInHomogeneousFieldsTest )
{
    const Vector centerCoordinate{ 5., 5., 5. };
    const Vector zeroSpeed{ 0., 0., 0. };
    const ParticleOptions electronOptions = ParticleOptionsCatalog::getElectronOptions();

    ElectronInHomogeneousFieldsCoub coub;
    coub.setDeltaTime( 1e-13 );
    coub.setBorders( Vector{ 10., 10., 10. } );

    std::list< IDType > electronIds;
    const ParticleGroupList& particleGroup = coub.getUniqParticleGroupList();

    particleGroup.forEachParticle(
        [ & ]( ParticlePtr particle ) { electronIds.push_back( particle->getId() ); } );

    for ( IDType id : electronIds )
    {
        particleGroup.forEachGroup(
            [ = ]( ParticleGroupPtr group ) { group->remove( id ); } );
    }

    coub.setElectricFieldDirection( Vector{ 1., 0., 0. } );
    coub.setElectricFieldCharge( 0. );
    coub.setMagneticFieldInduction( 0. );

    coub.addElectron( centerCoordinate, zeroSpeed, electronOptions );
    ParticlePtr electron = *( *particleGroup.cbegin() )->begin();

    coub.phyCoub();
    ASSERT_EQ( electron->getCoordinate(), centerCoordinate );

    Vector secondElectronCoordinate = centerCoordinate;
    secondElectronCoordinate.x() += 1e-5;

    coub.addElectron( secondElectronCoordinate, zeroSpeed, electronOptions );
    ParticlePtr secondElectron = *( ++( *particleGroup.cbegin() )->begin() );

    coub.setElectron2ElectronInterworkingFlag( true );

    coub.phyCoub();
    ASSERT_LT( electron->getCoordinate().x(), centerCoordinate.x() );
    ASSERT_GT( secondElectron->getCoordinate().x(), secondElectronCoordinate.x() );
}