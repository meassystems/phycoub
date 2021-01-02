cmake_minimum_required(VERSION 3.16)

project(phycommon VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 AddParticleControllerAdapterIface.h
	 GLRotationController.cpp
	 GLRotationController.h
	 GLRotationIface.h
	 GetCoubSizeAdapterIface.h
	 GetParticlesAdapterIface.h
	 ParticleRemoveControllerAdapterIface.h
	 PhyCoubController.cpp
	 PhyCoubController.h
	 PhyCoubControllerSubscriberIface.h
	 ValueControllerAdapterIface.h
)

add_library(phycommon OBJECT ${SOURCES})

