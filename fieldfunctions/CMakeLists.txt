cmake_minimum_required(VERSION 3.16)

project(fieldfunctions VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 DirectHomogeneousField.cpp
	 DirectHomogeneousField.h
	 ElectricField.cpp
	 ElectricField.h
	 ElectricHomogeneousDirectField.cpp
	 ElectricHomogeneousDirectField.h
	 ElectricHomogeneousRadialXYField.cpp
	 ElectricHomogeneousRadialXYField.h
	 FieldIface.h
	 HomogeneousFieldIface.h
	 LDField.cpp
	 LDField.h
	 MagneticHomogeneousDirectField.cpp
	 MagneticHomogeneousDirectField.h
	 RadialHomogeneousField.cpp
	 RadialHomogeneousField.h
)

add_library(fieldfunctions OBJECT ${SOURCES})

