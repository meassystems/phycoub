cmake_minimum_required(VERSION 3.16)

project(types VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 Vector.cpp
	 Vector.h
	 VectorUtils.cpp
	 VectorUtils.h
)

add_library(types OBJECT ${SOURCES})

