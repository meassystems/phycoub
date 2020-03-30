/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-27 09:26:39
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-30 10:11:51
 */

#include <iostream>
#include <string>

#include "NOCoub.h"
#include "ArCoub.h"
#include "FigureDemonstration.h"
#include "ElectronInHomogeneousFieldsCoub.h"
#include "Magnetron.h"
#include "WilsonCloudChamber.h"

using namespace phycoub;

int main()
{

    std::cout.precision( 17 );

    try
    {
        auto printVector = []( Vector vector, std::string name ) {
            std::cout << name << std::endl;
            std::cout << ( vector )[ 0 ] << " " << ( vector )[ 1 ] << " "
                      << ( vector )[ 2 ] << std::endl;
            std::cout << std::endl;
        };

        auto printMatrix = []( Matrix matrix, std::string name ) {
            std::cout << name << std::endl;
            for ( int i = 0; i < 3; ++i )
            {
                std::cout << ( matrix )[ i * 3 ] << " " << ( matrix )[ i * 3 + 1 ] << " "
                          << ( matrix )[ i * 3 + 2 ] << std::endl;
            }
            std::cout << std::endl;
        };

        auto printAlInfo = [printVector, printMatrix]( ConeParticleSourcePtr source ) {
            std::cout << "//////////////////////////////////////////////////////////"
                      << std::endl;

            printVector( source->getGuideCosines(), "Direction Cosines:" );
            printVector( source->zRotationMatrix_.cosines_, "zRotation Cosines:" );
            printMatrix( source->zRotationMatrix_.matrix_, "zRotationMatrix:" );
            printVector( source->yRotationMatrix_.cosines_, "yRotation Cosines:" );
            printMatrix( source->yRotationMatrix_.matrix_, "yRotationMatrix:" );

            printVector(
                source->phyGiveBirthParticle()->getSpeed(), "Result Direction:" );

            std::cout << std::endl;
        };

        while ( true )
        {
            const double coneHeight = 1.;
            const double coneAngle = 0.;
            const Vector sourceCoordinate = { 0., 0., 0. };
            const double energy = 1e-17;

            const ParticleOptions electronOptions{ ElectricConstants::electronWeight,
                ElectricConstants::electronCharge };

            const Vector guideCosines{ 1., 0., 0. };

            ConeParticleSourcePtr electronConeParticleSource_
                = std::make_shared< ConeParticleSource >( guideCosines, coneHeight,
                    coneAngle, sourceCoordinate, electronOptions, energy );

            printAlInfo( electronConeParticleSource_ );

            electronConeParticleSource_->setGuideCosines( { -1., 0., 0. } );
            printAlInfo( electronConeParticleSource_ );
            electronConeParticleSource_->setGuideCosines( { 0., 1., 0. } );
            printAlInfo( electronConeParticleSource_ );
            electronConeParticleSource_->setGuideCosines( { 0., -1., 0. } );
            printAlInfo( electronConeParticleSource_ );
            electronConeParticleSource_->setGuideCosines( { 0., 0., 1. } );
            printAlInfo( electronConeParticleSource_ );
            electronConeParticleSource_->setGuideCosines( { 0., 0., -1. } );
            printAlInfo( electronConeParticleSource_ );

            break;
        }
    }
    catch ( char const* str )
    {
        std::cout << str;
    }
    /*
    try
    {
        WilsonCloudChamber WilsonCloudChamber;
        while ( true )
        {
            WilsonCloudChamber.phyCoub();
        }
    }
    catch ( char const* str )
    {
        std::cout << str;
    }
    */
    /*
        try
        {
            Magnetron magnetron;

            while ( true )
            {
                magnetron.phyCoub();
                const ParticleGroupList& particleGroupList
                    = magnetron.getUniqParticleGroupList();

                particleGroupList.forEachParticle( []( ParticlePtr particle ) {
                    const Vector& coordinate = particle->getCoordinate();
                    std::cout << coordinate.x_ << " ; " << coordinate.y_ << " ; "
                              << coordinate.z_ << std::endl;
                } );
            }
        }
        catch ( char const* str )
        {
            std::cout << str;
        }
    */
    /*
    try
    {
        ElectronInHomogeneousFieldsCoub electronInHomogeneousFieldsCoub;
        electronInHomogeneousFieldsCoub.setElectron2ElectronInterworkingFlag( true );
        electronInHomogeneousFieldsCoub.setElectron2ElectronInterworkingFlag( false );

        while ( true )
        {
            electronInHomogeneousFieldsCoub.phyCoub();
        }
    }
    catch ( char const* str )
    {
        std::cout << str;
    }
    */
    /*
    try
    {
        NOCoub NOPhyCoub;
        while ( true )
        {
            NOPhyCoub.phyCoub();
            std::cout << NOPhyCoub.azot_->front()->getCoordinate().z_
                    - NOPhyCoub.oxygen_->front()->getCoordinate().z_
                      << " ; " << NOPhyCoub.azot_->front()->getSpeed().z_ << std::endl;
        }
    }
    catch ( char const* str )
    {
        std::cout << str;
    }
    */
    /*
    try
    {
        ArCoub ArCoub;
        while ( true )
        {
            ArCoub.phyCoub();
            std::cout << ArCoub.argon_->front()->getCoordinate().x_ << " ; "
                      << ArCoub.argon_->front()->getCoordinate().y_ << " ; "
                      << ArCoub.argon_->front()->getCoordinate().z_;
            std::cout << "	-	" << ArCoub.argon_->back()->getCoordinate().x_
                      << " ; " << ArCoub.argon_->back()->getCoordinate().y_ << " ; "
                      << ArCoub.argon_->back()->getCoordinate().z_ << std::endl;
        }
    }
    catch ( char const* str )
    {
        std::cout << str;
    }
    */
    /*
        try
        {
            FigureDemonstration figureDemonstration;
            while ( true )
            {
                figureDemonstration.phyCoub();
                std::cout <<
       figureDemonstration.lineN.particles_->front()->getCoordinate().x_
                          << " ; "
                          <<
       figureDemonstration.lineN.particles_->front()->getCoordinate().y_
                          << " ; "
                          <<
       figureDemonstration.lineN.particles_->front()->getCoordinate().z_; std::cout << "
       -
       "
                          <<
       figureDemonstration.lineN.particles_->back()->getCoordinate().x_
                          << " ; "
                          <<
       figureDemonstration.lineN.particles_->back()->getCoordinate().y_
                          << " ; "
                          <<
       figureDemonstration.lineN.particles_->back()->getCoordinate().z_
                          << std::endl;
            }
        }
        catch ( char const* str )
        {
            std::cout << str;
        }
    */
    return 0;
}
