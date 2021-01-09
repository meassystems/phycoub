cmake_minimum_required(VERSION 3.16)

project(addparticle VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 PhyAddParticlePhyCoubSubscriber.cpp
	 PhyAddParticlePhyCoubSubscriber.h
	 PhyAddParticleWidget.cpp
	 PhyAddParticleWidget.h
)

add_library_with_phycoub_dependency(addparticle OBJECT ${SOURCES})

