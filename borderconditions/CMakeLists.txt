cmake_minimum_required(VERSION 3.16)

project(borderconditions VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 BorderCondition.cpp
	 BorderCondition.h
	 CyclicBorder.cpp
	 CyclicBorder.h
	 CylinderBorderCondition.cpp
	 CylinderBorderCondition.h
	 ElasticCoubCondition.cpp
	 ElasticCoubCondition.h
	 ThermostatBorder.cpp
	 ThermostatBorder.h
)

add_library(borderconditions OBJECT ${SOURCES})

