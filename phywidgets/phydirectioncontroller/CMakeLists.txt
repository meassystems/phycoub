cmake_minimum_required(VERSION 3.16)

project(phydirectioncontroller VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 PhyDirectionControllerWidget.cpp
	 PhyDirectionControllerWidget.h
)

add_library(phydirectioncontroller OBJECT ${SOURCES})

