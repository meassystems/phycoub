cmake_minimum_required(VERSION 3.16)

project(directiongl VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 GLRotationDirectionViewAdapter.cpp
	 GLRotationDirectionViewAdapter.h
	 PhyDirectionGLWidget.cpp
	 PhyDirectionGLWidget.h
)

add_library(directiongl OBJECT ${SOURCES})

