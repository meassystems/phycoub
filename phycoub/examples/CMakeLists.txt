cmake_minimum_required(VERSION 3.16)

project(examples VERSION 1.0)

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
	 WilsonCloudChamber.cpp
	 WilsonCloudChamber.h
)

add_library_with_eigen_dependency(examples OBJECT ${SOURCES})

