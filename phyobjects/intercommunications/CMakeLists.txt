cmake_minimum_required(VERSION 3.16)

project(intercommunications VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 InterCommunication.cpp
	 InterCommunication.h
	 InterGroupCommunication.cpp
	 InterGroupCommunication.h
	 InterworkingCalculatorBase.cpp
	 InterworkingCalculatorBase.h
)

add_library(intercommunications OBJECT ${SOURCES})

