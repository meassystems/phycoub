cmake_minimum_required(VERSION 3.16)

project(coubcontroller VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 PhyCoubControllerSubscriber.cpp
	 PhyCoubControllerSubscriber.h
	 PhyCoubControllerWidget.cpp
	 PhyCoubControllerWidget.h
)

add_library_with_phycoub_dependency(coubcontroller OBJECT ${SOURCES})

