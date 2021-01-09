cmake_minimum_required(VERSION 3.16)

project(particleoptionscontroller VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 PhyParticleOptionsControllerWidget.cpp
	 PhyParticleOptionsControllerWidget.h
)

add_library_with_phycoub_dependency(particleoptionscontroller OBJECT ${SOURCES})

