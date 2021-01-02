#include "gmock/gmock.h"

#include "BorderReachedObserver.h"

using namespace phycoub;

class BorderReachedObserverMock: public BorderReachedObserver {
  public:
    MOCK_METHOD(void, onBorderReached, (ParticlePtr particle), (override));
};
