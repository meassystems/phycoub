cmake_minimum_required(VERSION 3.16)

project(phycoubs VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 ArCoub.cpp
	 ArCoub.h
	 ElectronInHomogeneousFieldsCoub.cpp
	 ElectronInHomogeneousFieldsCoub.h
	 FigureDemonstration.cpp
	 FigureDemonstration.h
	 Magnetron.cpp
	 Magnetron.h
	 NOCoub.cpp
	 NOCoub.h
	 PhyCoub.cpp
	 PhyCoub.h
)

add_library(phycoubs OBJECT ${SOURCES})

