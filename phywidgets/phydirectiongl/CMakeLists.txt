cmake_minimum_required(VERSION 3.16)

project(phydirectiongl VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 GLRotationDirectionViewAdapter.cpp
	 GLRotationDirectionViewAdapter.h
	 PhyDirectionGLWidget.cpp
	 PhyDirectionGLWidget.h
)

add_library(phydirectiongl OBJECT ${SOURCES})

