cmake_minimum_required(VERSION 3.16)

project(phymeasurement VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 MeasurementUtils.cpp
	 MeasurementUtils.h
)

add_library(phymeasurement OBJECT ${SOURCES})

