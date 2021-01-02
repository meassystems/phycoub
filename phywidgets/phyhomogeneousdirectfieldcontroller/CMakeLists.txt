cmake_minimum_required(VERSION 3.16)

project(phyhomogeneousdirectfieldcontroller VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 HomogeneousFieldControllerWidget.cpp
	 HomogeneousFieldControllerWidget.h
	 PhyHomogeneousDirectFieldControllerWidget.cpp
	 PhyHomogeneousDirectFieldControllerWidget.h
)

add_library(phyhomogeneousdirectfieldcontroller OBJECT ${SOURCES})

