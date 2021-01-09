cmake_minimum_required(VERSION 3.16)

project(borderevents VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 BorderReachedEventGenerator.cpp
	 BorderReachedEventGenerator.h
	 BorderReachedObserver.h
)

add_library_with_eigen_dependency(borderevents OBJECT ${SOURCES})

