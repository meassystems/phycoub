cmake_minimum_required(VERSION 3.16)

project(shapes VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 CubicShape.cpp
	 CubicShape.h
	 CylindricShape.cpp
	 CylindricShape.h
)

add_library(shapes OBJECT ${SOURCES})

