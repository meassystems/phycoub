cmake_minimum_required(VERSION 3.16)

project(homogeneousdirectfieldcontroller VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 HomogeneousFieldControllerWidget.cpp
	 HomogeneousFieldControllerWidget.h
	 PhyHomogeneousDirectFieldControllerWidget.cpp
	 PhyHomogeneousDirectFieldControllerWidget.h
	 HomogeneousFieldInCubeGL.h
	 HomogeneousFieldInCubeGL.cpp
)

add_library(homogeneousdirectfieldcontroller OBJECT ${SOURCES})

