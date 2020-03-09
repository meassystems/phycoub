cmake_minimum_required(VERSION 3.16)

project(fieldcreators VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 DynamicFieldCreator.cpp
	 DynamicFieldCreator.h
	 FieldCreator.cpp
	 FieldCreator.h
	 HomogeneousFieldCreator.cpp
	 HomogeneousFieldCreator.h
)

add_library(fieldcreators OBJECT ${SOURCES})

