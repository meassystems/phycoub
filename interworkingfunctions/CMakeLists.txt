cmake_minimum_required(VERSION 3.16)

project(interworkingfunctions VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 CulonInterworking.cpp
	 CulonInterworking.h
	 InterworkingIface.h
	 LDInterworking.cpp
	 LDInterworking.h
	 MagneticInterworking.cpp
	 MagneticInterworking.h
)

add_library(interworkingfunctions OBJECT ${SOURCES})

