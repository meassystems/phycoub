cmake_minimum_required(VERSION 3.16)

project(lifetimecontrollers VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 BornPeriodLifeTimeController.cpp
	 BornPeriodLifeTimeController.h
	 LifeTimeControllerBase.cpp
	 LifeTimeControllerBase.h
	 LifeTimeControllerIface.h
	 QuantityLifeTimeController.cpp
	 QuantityLifeTimeController.h
	 RemoveParticleIfBorderReachedBase.cpp
	 RemoveParticleIfBorderReachedBase.h
)

add_library_with_eigen_dependency(lifetimecontrollers OBJECT ${SOURCES})

