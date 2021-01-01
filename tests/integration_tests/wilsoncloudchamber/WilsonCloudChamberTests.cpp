#include "WilsonCloudChamberTests.h"

#include "WilsonCloudChamber.h"

using namespace phycoub;

TEST_F( WilsonCloudChamberTests, WilsonCloudChamberTest )
{
    const double dt = 1e-15;

    WilsonCloudChamber wilsonCloudChamber;
    wilsonCloudChamber.setDeltaTime(dt);

    const ParticleGroupList& particleGroup = wilsonCloudChamber.getUniqParticleGroupList();
    ASSERT_EQ( particleGroup.getParticleCount(), 0 );

    wilsonCloudChamber.setElectronSourcBornPeriod(2.7 * dt);
    wilsonCloudChamber.setProtonSourcBornPeriod(1.7 * dt);

    wilsonCloudChamber.phyCoub();
    wilsonCloudChamber.phyCoub();
    ASSERT_EQ( particleGroup.getParticleCount(), 1 );

    wilsonCloudChamber.phyCoub();
    ASSERT_EQ( particleGroup.getParticleCount(), 2 );

    wilsonCloudChamber.setElectronSourcBornPeriod(0.);
    wilsonCloudChamber.setProtonSourcBornPeriod(0.);

    wilsonCloudChamber.phyCoub();
    wilsonCloudChamber.phyCoub();
    ASSERT_EQ( particleGroup.getParticleCount(), 2 );

    wilsonCloudChamber.setSpecificSourcBornPeriod(0.7 * dt);
    wilsonCloudChamber.phyCoub();
    ASSERT_EQ( particleGroup.getParticleCount(), 3 );
}