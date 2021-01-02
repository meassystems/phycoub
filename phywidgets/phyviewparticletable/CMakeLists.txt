cmake_minimum_required(VERSION 3.16)

project(phyviewparticletable VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 PhyViewParticleTableWidget.cpp
	 PhyViewParticleTableWidget.h
)

add_library(phyviewparticletable OBJECT ${SOURCES})

