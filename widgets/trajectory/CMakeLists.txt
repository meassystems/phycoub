cmake_minimum_required(VERSION 3.16)

project(trajectory VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 Trajectory.cpp
	 Trajectory.h
)

add_library_with_phycoub_dependency(trajectory OBJECT ${SOURCES})

