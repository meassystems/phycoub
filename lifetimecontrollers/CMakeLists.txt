cmake_minimum_required(VERSION 3.16)

project(lifetimecontrollers VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 LifeTimeControllerIface.h
	 QuantityLifeTimeController.cpp
	 QuantityLifeTimeController.h
)

add_library(lifetimecontrollers OBJECT ${SOURCES})

