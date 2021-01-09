cmake_minimum_required(VERSION 3.16)

project(phyobjects VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 CalculationGroup.cpp
	 CalculationGroup.h
	 FieldReceiver.cpp
	 FieldReceiver.h
	 PhyCoub.cpp
	 PhyCoub.h
)

add_library_with_eigen_dependency(phyobjects OBJECT ${SOURCES})

