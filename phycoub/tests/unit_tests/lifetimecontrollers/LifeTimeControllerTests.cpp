#include "LifeTimeControllerTests.h"

#include "QuantityLifeTimeController.h"
#include "CylindricalXYParticleSource.h"

using namespace phycoub;

TEST_F( LifeTimeControllerTests, QuantityLifeTimeController )
{
    ParticleOptions particleOptions{ 1., 1. };
    std::shared_ptr< CylindricalXYPartcleSource > particleSourcePtr
        = std::shared_ptr< CylindricalXYPartcleSource >{ new CylindricalXYPartcleSource(
            1., 1., Vector{ 0., 0., 0. }, particleOptions, 1. ) };

    ParticleGroupPtr particleGroup = std::make_shared<ParticleGroup>();

    constexpr uint numLifeParticleCount = 10;
    QuantityLifeTimeController quantityLifeTimeController{ numLifeParticleCount, particleSourcePtr };
    quantityLifeTimeController.setParticleGroup(particleGroup);

    ASSERT_EQ( particleGroup->size(), 0 );
    quantityLifeTimeController.phyControlLifeTime();
    ASSERT_EQ( particleGroup->size(), numLifeParticleCount );

    quantityLifeTimeController.onBorderReached(*particleGroup->begin());
    quantityLifeTimeController.phyControlLifeTime();
    ASSERT_EQ( particleGroup->size(), numLifeParticleCount );
}
