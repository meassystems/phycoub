cmake_minimum_required(VERSION 3.16)

project(mathematic VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 Matrix.cpp
	 Matrix.h
	 RandomUtils.cpp
	 RandomUtils.h
	 RotationMatrix.cpp
	 RotationMatrix.h
	 Vector.cpp
	 Vector.h
	 VectorUtils.cpp
	 VectorUtils.h
)

add_library(mathematic OBJECT ${SOURCES})
