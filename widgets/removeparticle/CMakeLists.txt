cmake_minimum_required(VERSION 3.16)

project(removeparticle VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 PhyRemoveParticlePhyCoubSubscriber.cpp
	 PhyRemoveParticlePhyCoubSubscriber.h
	 PhyRemoveParticleWidget.cpp
	 PhyRemoveParticleWidget.h
)

add_library(removeparticle OBJECT ${SOURCES})

