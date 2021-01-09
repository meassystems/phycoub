cmake_minimum_required(VERSION 3.16)

project(particlefigurematrix VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 LineFigure.cpp
	 LineFigure.h
	 ParallelepipedFigure.cpp
	 ParallelepipedFigure.h
	 PlaneFigure.cpp
	 PlaneFigure.h
)

add_library_with_eigen_dependency(particlefigurematrix OBJECT ${SOURCES})

