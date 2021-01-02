cmake_minimum_required(VERSION 3.16)

project(calculationmodels VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 CalculationModel.cpp
	 CalculationModel.h
	 HighSpeedModificationVerle.cpp
	 HighSpeedModificationVerle.h
	 LeapFrog.cpp
	 LeapFrog.h
)

add_library(calculationmodels OBJECT ${SOURCES})

